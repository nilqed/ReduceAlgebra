%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           pthread_util.SL
% Description:    various useful functions for pthreads
% Author:         Winfried Neun, ZIB Berlin
% Created:        5 February 2007 (SUN4 version)
% Mode:           Lisp
% Package:        Utilities
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(setq status (gtwarray 1))
(wputv status 0 42)

(setq arg (gtwarray 1))

  % Numbers carefully taken from a C program with sizeofs ...
(de gtthread() (gtwarray 1))
(de gtthread_attr() (gtwarray 9))
(de gtthread_mutex() (gtwarray 6))

(setq mutex (gtthread_mutex))

(de psl_create_thread_nonblock (start argh)
  (prog (threa)
   (setq threa (gtthread))
   (pthread_mutex_init mutex 0)
   (wputv arg 0 argh)
   (pthread_create threa (gtthread_attr)
                (mkfixn (inf (getfcodepointer start))) arg)

%   (sleep 1) (print "waiting")  (pthread_mutex_lock mutex)
%   (print "waited")

   (return (wgetv threa 0))))

(de psl_create_thread (start argh)
  (prog (threa)
   (setq threa (gtthread))
   (pthread_mutex_init mutex 0)
   (wputv arg 0 argh)
   (pthread_create threa (gtthread_attr)
		(mkfixn (inf (getfcodepointer start))) arg)
   
%   (sleep 1) (print "waiting")  (pthread_mutex_lock mutex)
%   (print "waited")
   
   (pthread_join (wgetv threa 0) status)
   (return (wgetv status 0))))

(de guinea-pig () 
%%%                     (pthread_mutex_lock mutex)
%%%			(sleep 10)
%%%                     (pthread_mutex_unlock mutex)
      (pthread_exit (apply (car (wgetv arg 0)) (cdr (wgetv arg 0)))))


(load nbig32)
(de pthread_karatsuba (u v)
  (prog (lu lv u_up v_up u_low v_low mixed thr)
   (setq lu (bsize u))
   (setq lv (bsize v))
   (setq u_up (lshift u (minus (times2 (quotient (plus2 lu 1) 2) 32))))
   (setq v_up (lshift u (minus (times2 (quotient (plus2 lv 1) 2) 32))))
   (setq u_low (land (sub1 (lshift 2 (times2 (quotient lu 2) 32))) u))
   (setq v_low (land (sub1 (lshift 2 (times2 (quotient lv 2) 32))) v))
   (setq thr 
   (psl_create_thread_nonblock 'guinea-pig (list 'cons (list 'times2 u_up v_up))
                                              (list 'times2 u_low v_low)))
   (setq mixed (times2 (plus2 u_up u_low) (plus2 v_up v_low)))
   (pthread_join thr status)

))
   
   

(psl_create_thread 'guinea-pig (list 'member 999000 liste))
(print (wgetv status 0))
(psl_create_thread 'guinea-pig (list 'member 'a liste))
(print (wgetv status 0))
