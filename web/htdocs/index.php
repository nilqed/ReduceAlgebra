<!-- Index page for https://reduce-algebra.sourceforge.io/, http://reduce-algebra.com, etc. -->

<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
	<p>See also the <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">REDUCE project page at <img class="sflogo" alt="Download REDUCE" src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a>.</p>
	<p>REDUCE is a system for doing scalar, vector and matrix algebra by computer, which also supports arbitrary precision numerical approximation and interfaces to <a href="http://www.gnuplot.info/">gnuplot</a> to provide graphics. It can be used interactively for simple calculations (as illustrated in the screenshot below) but also provides a full programming language, with a syntax similar to other modern programming languages. REDUCE supports alternative <a href="support.php#interfaces">user interfaces</a> including Emacs and TeXmacs.</p>
	<p>REDUCE (and its complete source code) is <a href="obtaining.php">available free of charge</a> for most common computing systems, in some cases in more than one version (see below) for the same machine. The <a href="documentation.php">manual and other support documents</a> and tutorials are also included in the distributions.</p>
	<a href="images/reduce_screenshot_1.PNG">
	<img src="images/reduce_screenshot_1.PNG" alt="CSL REDUCE on Microsoft Windows"
	title="CSL REDUCE on Microsoft Windows - click to see the full size image" /></a>
	<p>REDUCE has a long and distinguished place in the history of computer algebra systems (see the <a href="bibliography.php">bibliography</a>). Other systems that address some of the same issues but sometimes with rather different emphasis are <a href="http://www.axiom-developer.org/">Axiom</a>, Macsyma (<a href="http://maxima.sourceforge.net/">Maxima</a>), <a href="http://www.maplesoft.com/products/Maple/">Maple</a> and <a href="http://www.wolfram.com/mathematica/">Mathematica</a>.</p>
	<p>REDUCE is implemented in Lisp (as are Axiom and Macsyma), but this is completely hidden from the casual user. REDUCE primarily runs on either <a href="versions.php">Portable Standard Lisp (PSL) or Codemist Standard Lisp (CSL)</a>, both of which are available in the distributions. PSL is long-established and compiles to machine code, whereas CSL is newer and compiles to byte code. Hence, PSL may be faster but CSL may be available on a wider range of platforms.</p>
END_OF_MAIN_CONTENT
);

$smarty->display('index.tpl');

?>
