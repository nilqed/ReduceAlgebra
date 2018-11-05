%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:BASE-IO.SL 
% Title:        System independent IO routines for PSL 
% Author:       Robert R. Kessler 
% Created:      16 August 1982 
% Modified:     20-Nov-84 13:17:17 (Brian Beach)
% Package:      Kernel 
% Status:       Open Source: BSD License
%
% (c) Copyright 1982, University of Utah
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
% Revisions:
%
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Changed declaration of in* and out* from global to fluid.
% 20-Nov-84 13:14:53 (Brian Beach)
%  Changed INDEPENDENTWRITECHAR so that the buffer overflow is computed more
%  accurately.  The Number of characters in the buffer when the buffer is 
%  written should now be exactly equal to the declared buffer size (instead
%  of two more, as it has been in the past.)
% 17-Jul-84 14:00 (Brian Beach)
%  Added missing STRINF's.
% 31-May-84 09:13:29 (Brian Beach)
%  Removed if-system for Chipmunk that handled tabs.  Exported the code
%  to the system specific terminal driver (in PHPP:HP.TEXT).
% 27-Mar-84 14:48:03 (Jim Ambras/CRC)
%  Added compiletime load of io-decls.
% 02-Dec-83 10:42:46 (Jim Ambras)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%==============================================================================
%
% Each individual system must have the following routines defined.
%
%   The following definitions are used in the routines:
%    FileDescriptor - A machine dependent word that references a file once
%      opened; generated by the Open
%    FileName - A Lisp string of the file name.
%
%  FileDescriptor := SysOpenRead (Channel,FileName);
%                                             % Open FileName for input and
%      % return a file descriptor used
%      % in later references to the
%      % file. Channel used only
%                                             % if needed to generate FileDesc
%  FileDescriptor := SysOpenWrite (Channel,FileName);
%                                             % Open FileName for output and
%      % return a file descriptor used
%      % in later references to the
%      % file. Channel used only
%                                             % if needed to generate FileDesc
%  SysWriteRec (FileDescriptor, StringToWrite, StringLength);
%      % Write StringLength characters
%      % from StringToWrite from the
%      % first position.
%  LengthRead := SysReadRec (FileDescriptor, StringBuffer);
%      % Read from the FileDescriptor, a
%      %  record into the StringBuffer.
%      %  Return the length of the
%      %  string read.
%  SysClose (FileDescriptor);      % Close FileDescriptor, allowing
%      %  it to be reused.
%
%==============================================================================

(compiletime
  (load fast-vector if-system))

(compiletime
 (load io-decls))

(on fast-integers)

(fluid '(in* out*))

(fluid '(stdin*
	 stdout*
	 errout*
	 promptout*
	 *echo
	 iobuffer
	 ))


(de findfreechannel ()

  %  Look into the ChannelStatus array for a free channel.

  (let ((channel 0))
    (while (neq (wgetv channelstatus channel) channelclosed)
      (when (> channel (- maxchannels 2))
	(ioerror "No free channels left"))
      (setq channel (+ channel 1)))
    channel
    ))


(de systemopenfileforinput (filename)

  %   Open the argument filename as a read only file.

  (let ((channel (findfreechannel)))
    (setf (wgetv channeltable  channel) (sysopenread channel filename))
    (setf (wgetv channelstatus channel) channelopenread)
    (setf (wgetv maxbuffer     channel) (sysmaxbuffer (wgetv channeltable channel)))
    (setf (wgetv readfunction  channel) 'independentreadchar)
    (setf (wgetv writefunction channel) 'readonlychannel)
    (setf (wgetv closefunction channel) 'independentclosechannel)
    (setf (wgetv nextposition  channel) 0)   % Will be post Incremented
    (setf (wgetv bufferlength  channel) -1)
    (setf (igetv iobuffer      channel) (mkstring (wgetv maxbuffer channel) 32))
    channel
    ))


(de systemopenfileforoutput (filename)

  % Open the argument file name as a write only file.

  (let ((channel (findfreechannel)))
    (setf (wgetv channeltable  channel) (sysopenwrite channel filename))
    (setf (wgetv channelstatus channel) channelopenwrite)
    (setf (wgetv maxbuffer     channel) (sysmaxbuffer (wgetv channeltable channel)))
    (setf (wgetv readfunction  channel) 'writeonlychannel)
    (setf (wgetv writefunction channel) 'independentwritechar)
    (setf (wgetv closefunction channel) 'independentclosechannel)
    (setf (igetv iobuffer      channel) (mkstring (wgetv maxbuffer channel) 32))
    (setf (wgetv nextposition  channel) -1)   % Will be set pre-incremented
    (setf (wgetv bufferlength  channel) (wgetv maxbuffer channel))
    channel
    ))


(de systemopenfilespecial (filename)

  %  Mark a channel as open for a special purpose.

  (let ((channel (findfreechannel)))
    (setf (wgetv channelstatus channel) channelopenspecial)
    channel
    ))


(de testlegalchannel (channel)

  % Cause an error if CHANNEL is not legal.
  
  (unless (and (posintp channel) (< channel maxchannels))
    (ioerror (list channel " is not a legal channel "))))


(de independentreadchar (channel)

  % This function will read in a character from the buffer.  It will read
  % the record on buffer length overflow only.  Thus when an EOL character
  % is read, it is processed as any other character, except, if it is the last
  % one, in the record, it will do the read automatically.
  % Note, this will not read the next record until after the final character
  % has been processed.

  (testlegalchannel channel)

  % If the input buffer is empty, read another buffer full:
  
  (when (wgreaterp (wgetv nextposition channel)
		   (wgetv bufferlength channel))
    (setf (wgetv bufferlength channel)
      (sysreadrec (wgetv channeltable channel)
		  (igetv iobuffer channel)))
    (setf (wgetv nextposition channel) 0))

  % Pull the next character out of the buffer.
  
  (let ((chr (wand 16#ff (strbyt (strinf (igetv iobuffer channel))
                     (wgetv nextposition channel)))))
    (setf (wgetv nextposition channel) (+ (wgetv nextposition channel) 1))
    (when *echo
      (writechar chr))
    chr
    ))


(de independentwritechar (channel chr)

  % Write a character into the buffer.  Actually dump the buffer when the
  % EOL character is found, or when the buffer is full.  This happens
  % immediately upon meeting this condition, not waiting for the
  % next character.  Note, that this places the EOL character into the
  % buffer for machine dependent treatment as CR/LF etc

  (testlegalchannel channel)
  (setf (wgetv nextposition channel) (+ (wgetv nextposition channel) 1))
  (setf (strbyt (strinf (igetv iobuffer channel)) 
                (wgetv nextposition channel))
    chr)
  (when (or (equal chr (char eol))
	    (>= (iadd1 (wgetv nextposition channel))  % Indexed from 0
		(wgetv bufferlength channel)))        % Number of characters
    (flushbuffer channel)
    )
  )


(de flushbuffer (channel)

  % Actually output any characters still hanging around in the buffer.

  (when (wgreaterp (wgetv nextposition channel) -1)
	(syswriterec (wgetv channeltable channel)
	       (igetv iobuffer channel)
	       (wgetv nextposition channel)))
  (setf (wgetv nextposition channel) -1)
  )


(de systemmarkasclosedchannel (channel)

  % Mark the argument channel as closed and update the read, write and
  % close functions likewise.  Careful, if the caller does this first
  % and then trys to access a read, write or close function we are
  % in big trouble.  Is it correct to do this?????  Or is a marking of
  % the channel status table sufficient.

  (testlegalchannel channel)
  (setf (wgetv channelstatus channel) channelclosed)
  (setf (wgetv readfunction  channel) 'channelnotopen)
  (setf (wgetv writefunction channel) 'channelnotopen)
  (setf (wgetv closefunction channel) 'channelnotopen)
  )


(de independentclosechannel (channel)

  % Actually close the argument channel.

  (testlegalchannel channel)
  (unless (eq (wgetv writefunction channel) 'readonlychannel)
	 (flushbuffer channel))
  (sysclose (wgetv channeltable channel))
  )


(de clearonechannel (chn filedes how fn)
  % Initialize Channel Tables, etc for initial "hand-built" channels
  % Assume these not CLOSEABLE

  (let ((bufflen  (sysmaxbuffer filedes)))

    (setf (wgetv channeltable  chn) filedes)
    (setf (wgetv maxbuffer     chn) bufflen)
    (setf (wgetv nextposition  chn) 0)
    (setf (wgetv lineposition  chn) 0)
    (setf (wgetv pageposition  chn) 0)
    (setf (wgetv unreadbuffer  chn) 0)
    (setf (wgetv closefunction chn)  'illegalstandardchannelclose)

    (if (weq how 'input)
      (progn (setf (wgetv bufferlength   chn) -1)
	     (setf (wgetv channelstatus  chn)  channelopenread)
	     (setf (wgetv readfunction   chn) fn)
	     (setf (wgetv writefunction  chn) 'readonlychannel)
	     )
      (progn (setf (wgetv nextposition   chn) -1)
	     (setf (wgetv bufferlength   chn) (wgetv maxbuffer chn))
	     (setf (wgetv channelstatus  chn)  channelopenwrite)
	     (setf (wgetv readfunction   chn) 'writeonlychannel)
	     (setf (wgetv writefunction  chn) fn)
	     )
      )
    (setf (igetv iobuffer chn) (mkstring bufflen 32))
    ))


(de cleario nil
  (unless (vectorp iobuffer)
    (setf iobuffer (mkvect maxchannels))
    )
  (syscleario)
  (setf in*  stdin*)
  (setf out* stdout*)
  )


%     2/24/84 - rrk We are getting an extra carriage return before printing
% the result of every evaluation of the top loop.  This is caused because
% of our method of handling prompts.  We write a prompt to the the
% promptout channel.  Write is the only thing that updates the lineposition
% numbers.  Thus, when we come around to printout the results, it looks
% like the prompt has reset the lineposition (length prompstring).  In some
% implementations, promptout and terminal out are the same channel, thus
% the call to posn returns something non zero.  This will not happen when
% the channel numbers are different.  Therefore to make it all work
% together, the following line will check to see if the two channels are
% the same, and reset the lineposition to 0 if they are.  We could have
% ignored the test in favor of always setting the position to 0, but that
% may be inconsistent with the philosophy that all writes update the
% lineposition (however one could argue that the prompt write is special
% and should not update the lineposition).  I'll leave the test in, and
% leave it to future bug reports if this is not what is expected.

(de terminalinputhandler (channel)
  (testlegalchannel channel)

  (when (> (wgetv nextposition channel) (wgetv bufferlength channel))
    (channelwritestring promptout* (if (stringp promptstring*)
				     promptstring*
				     ">"))
    (flushbuffer promptout*)
    (when (weq promptout* stdout*)
      (setf (wgetv lineposition promptout*) 0))
    (setf (wgetv bufferlength channel) 
      (sysreadrec (wgetv channeltable channel) (igetv iobuffer channel)))
    (setf (wgetv nextposition channel) 0))

  (let ((chr (wand 16#ff (strbyt (strinf (igetv iobuffer channel)) (wgetv nextposition channel)))))
    (setf (wgetv nextposition channel)  (+ (wgetv nextposition channel) 1))
    (when *echo
      (writechar chr))
    chr
    ))


(off fast-integers)
