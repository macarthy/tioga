# tioga


This is the README for the Tioga kernel, version 1.14, June 10, 2011.

    Copyright (C) 2005, 2006, 2007, 2008, 2009  Bill Paxton
    Copyright (C) 2007, 2008, 2009, 2010, 2011 Vincent Fourmond, Taro Sato, 
    	      	  Benjamin ter Kuile
    
    This file is part of Tioga.
    
    Tioga is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Library Public License as published
    by the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    
    Tioga is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Library General Public License for more details.
    
    You should have received a copy of the GNU Library General Public License
    along with Tioga; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

<< What's new >>

    Tioga 1.19.1 is a bugfix release that fixes installation problems
with recent Ruby versions and gets rid of an ugly warning.

<< Quick Installation of Tioga >>

    Are you feeling lucky?  If so, try QUICK_INSTALL.  This simply
does the steps for you that are described below.  The install needs to
copy some files to the ruby directory.  On the Mac, this probably
means you need to do the whole thing with a 'sudo'.  For Linux, you
may have to become root.  Once you've taken care of that, just run the
QUICK_INSTALL script and keep your fingers crossed.

    You now have the option to run HOME_INSTALL instead, which will
install the files to your home directory (no root privileges
needed). You just need to set your RUBYLIB environment variable as
reminded at the end of the file.

    Please check that there are 0 failures and 0 errors at the end of
the test.  Then, in your favorite PDF previewer, open the newly
created 'tests/Icon_Test.pdf' and compare it to the prebuilt
'samples/Icon.pdf'.  They should be very similar!  If it all seems to
be working, go directly to the << Documentation >> section below.


<< Step-by-Step Installation >>

    To get Tioga running, you need to have a working Ruby, a C
compiler, make, and pdflatex.  Assuming you've got all that (more
later if you don't), connect to the Tioga directory that you just
unpacked and do the following:

  [ this has been changed, be careful ! ]

    ruby setup.rb config
    ruby setup.rb seutp
    ruby setup.rb install

    (that's exactly what the ./QUICK_INSTALL script is doing)

    Tioga now uses the standard setup.rb installation tool, so you get
a lot of customization possibilities for free. For more information on
how to use setup.rb to suit your needs, try

    ruby setup.rb --help

or, even better, take a look at its documentation:

http://i.loveruby.net/en/projects/setup/doc/usage.html

<< Checking The Installation >>

    To make sure at least something works of out the newly installed
stuff, change directory to your new Tioga folder.  Then enter this to
the shell:

    cd tests
    ruby ts_Tioga.rb
    
This should produce something like the following if the install worked:

	Loaded suite ts_Tioga
	Started
	.....................................................
	compressed from 0 to 8
	compressed from 13 to 21
	compressed from 70 to 69
	compressed from 3631 to 1642
	.pdflatex -interaction nonstopmode Icon_Test.tex > pdflatex.log
 
 
 
	>>> NOTE: please look at tests/Icon_Test.pdf and compare it to samples/Icon.pdf
	.
	Finished in 0.501211 seconds.

	55 tests, 647 assertions, 0 failures, 0 errors

[the numbers here are not up-to-date, tests are added everytime a
feature is added, so it is likely the numbers you see are greater - it
means we're actually working ;-) !]

These tests ensure that Tioga is accessible and that some of the basic
stuff is working.  Don't skip the visual check of the newly created
file 'tests/Icon_Test.pdf'.  If that's ok, there's a good chance your
installation is up and running.

The next step is to do the tutorial found in the documentation.



<< Tutorial >>

    Once you have Tioga installed, the on-line tutorial will help you
get started using it.
    
http://tioga.rubyforge.org/doc/classes/Tioga/Tutorial.html


<< Documentation >>

    Visit this website to access the documentation:
    
        http://tioga.rubyforge.org/doc/

If for some reason that link isn't working, go to my website,

        http://www.kitp.ucsb.edu/~paxton

and check there for a new link to the Tioga stuff.

    Try to get by with the on-line documentation, but if you really
have a need to rebuild the documentation using Rdoc, I've
included a .document file in the release folder.  However, all
the figures have direct links to jpegs on my website, so you'll
either have to live with that, or do a bunch of edits.  Send me
an email if you'd like a tar file of the images.


<< Open Source >>

    You are welcome to take the Tioga source and do what you want with
it (within the bounds of the GNU license of course).  But don't even
think about asking for support from me for debugging your new stuff!
I have enough trouble with my own bugs to keep me busy endlessly!  But
if it looks like a bug in Tioga, please do let me know so I can try to
fix it.  Or even better, let me know the fix along with the bug!


----------------------------------

For more, visit my website:  http://www.kitp.ucsb.edu/~paxton

Best wishes,
Bill Paxton


	
<< What's old >>

Here are the old release messages:

    Tioga 1.19 is essentially a bugfix release, but it brings in an
important new feature: the ability to customize the resolution of the
PDF file produced. Up until version 1.18, the resolution was always
1/10th of a postscript point, but from now on, you can change that by
giving the scaling factor (default 10, as before), as an argument to
FigureMaker.new.

    Tioga 1.18 brings in a few new features. First, Dvector.fancy_read
is now able to extract pure text columns. Second, a jpg_info function
has been added that read the width and height from within a JPEG file,
for use with show_image: you now don't have to know the image size
beforehand. A load_png function was added that relies on pdflatex to
read PNG files (except those with a custom palette). Feed the return
value of load_png to show_image. It is now possible to reuse an image
over and over again by saving its reference and using itagain.Finally,
more control over the number of pdflatex executions is now available.
There are also a couple of bug fixes.


    Tioga 1.17 provides all the necessary fixes to have it run on
windows, so now we also support the Redmond operating system (works
with the ProTeXt LaTeX distribution).

    Tioga 1.16 brings in a bug fix by Josiah Schwab in handling some
HLS triplets. It also provides facilities to extract the pdflatex
errors.

    Tioga 1.15 brings in some new iterators in Dvector and some minor
bug fixes (in particular for gem builds).

    Tioga 1.14 fixes all known problems of Tioga with Ruby 1.9.1 and
higher (to the point that it runs with ctioga2, and the samples run
too !).

    It also brings in the possibility to customize the number of major
ticks after which log plots don't show minor ticks, via the
log_minor_ticks_limit accessor.

          --------------------------------------------------


   Tioga 1.13 brings in a fix for a well-hidden memory leak that was
unlikely to hit you unless you were allocating a huge number of
vectors.

   More interestingly, a few instance functions that did not depend on
FigureMaker's internal state (color conversion functions and
contouring algorithms) were made available as module functions too.

          --------------------------------------------------

    Tioga 1.12 has seen quite a lot of action. The first and major
change is the switch from a custom rewrite of mkmf.rb for
building/installing to the standard setup.rb tool, which finally has
the gem version build exactly the same way as the pristine one.

    Another side effect of this is that, for a big part thanks to
Carlo E. Prelz <fluido@fluido.as>, we now have tioga that works just
fine with Ruby 1.9.1 (though there is a weird bug while testing the
Flate library, we welcome any input on that).

    Apart from that, Tioga has seen many improvements on the numerical
side. First, we welcome the participation of Benjamin ter Kuile, who
has started improving some aspects of Dtable.

    Second, now Dvector is gifted with FFT capacities if the
development files of fftw3 are available at compile time (have a look
at the documentation).

    Third, Function has been endowed with a whole bunch of new
functions for data processing, such as linear regression, spline
approximation (that almost looks like a good filter !), 4th order
accurate first and second derivatives.

    Finally, a couple of annoying bugs were fixed.


--------------------------

    Version 1.11 brings in a few new features. First, it is now
possible to set the color of axis tick labels - if you love pink axes,
you can them fully in Pink, now ;-) ! Check out the
x/yaxis_labels_color= accessors. The show_axis/axis_info functions
have been updated accordingly, and are now complete.

    Second, a new interpolation function for monotonic interpolations
has been added to Dvector (check out the Sampled_pm_cubics sample in
samples/plots/plots.rb).


--------------------------

    Version 1.10 is a minor bug-fix release, the most important one
being that save_legend_info now draws markers with the proper line
style.

    In addition, a patch was provided by Benjamin ter Kuile
<bterkuile@gmail.com> to ease (and quicken) the interpolation of
non-uniform 3D-data unto a uniform grid. Thanks !

--------------------------

  Version 1.9: 

  zlib's source has been included again to fix compilation problems on
MacOS. The embedded copy will only be used if tioga does not manage to
link to the system one.

  It is now possible to use directly a HLS image using 'color_space' =
'HLS' as argument to show_image.

  A new ticks placement algorithm was written. You can benefit from it
by saying t.vincent_or_bill = true.

  You can now use the optional argument to show_legend to draw a
background (or anything else) to a legend. The information given to
the callback will only be accurate if t.measure_legends = true. See
samples/plots.rb
(Legend_Inside_with_Background_using_legend_background) for more
information. Accordingly, you can use legend_text_width to know the
legend's text maximal width. 

  A new utility function was written, show_grid, that draws a grid
according to major and optionally minor ticks of the current axes.

  show_marker can now take arrays for 'marker' and 'color', and cycles
through them while plotting.

  Some top-level convenience functions have been added:
FigureMaker.exec, FigureMaker.make_pdf,
FigureMaker.def_enter_page_function, FigureMaker.page_style that work
on the default FigureMaker.

  show_plot_without_clipping, obviously a non-clipping version of
show_plot.

  And all corresponding demonstrations in the samples/ directory !

--------------------------

    Version 1.8 is essentially a cleanup/bug fix release. Tioga now
compiles with hardly any warnings, thanks to the work by Taro
Sato. show_axis can now take a hash instead of a simple location, and
can draw axes basically anywhere. See the axes_fun function in
samples/plots/plots.rb and show_axis documentation. Few bugs were
fixed, in particular the position of ticks with
ticks_inside/ticks_outside, and the installation via Rubygems which
was broken for such a long time we are ashamed of it.


--------------------------

    Version 1.7 adds an option in legends for markers without any
line; just call save_legend_info with 'line_type' => 'None' in
addition to the marker information.  It is also now possible to give a
'legend' argument to show_marker.  The value of the arg can be either
a legend dictionary or simply the legend text in which case defaults
will be supplied for the rest.  There is an example of this in
samples/plots.rb in the Legend_Outside figure.

    It saw a very significant improvement in that you can now query
the exact size of a text typeset by LaTeX, with the function
text_size. Please have a look at its documentation, and at the
Text_size and Text_size_with_rotation samples in
samples/figures/figures.rb.

    The code base was quite moved around so as to facilitate work on a
Python version that would share as much code as possible with the Ruby
one; this should not bring user-visible changes (apart, maybe, from
compilation problems, but we hope not).

    Some bug fixes, including potential stack overflows (unprotected
snprintfs), and some new methods of Function. Dvector.fancy_read has
been reimplemented in C and benchmarked: it should be around three
times faster than before.

    Code should now compile cleanly with Ruby 1.9.

--------------------------

    Version 1.6 adds numeric label "frequency" and "phase" attributes
for both axes.  Previously Tioga assumed that every major tick mark
got a numeric label.  Now the i'th major tick on the axis gets a label
only if mod(i+j,k)==0 where j is the phase and k is the frequency.
The default frequency is naturally 1 so that every major tick gets a
label.  The full names for these attributes are
xaxis_numeric_label_frequency, xaxis_numeric_label_phase, and similar
for yaxis.

--------------------------

    Version 1.5 is mainly Vincent's work, so my part of this release
message will be short.  Remember how I killed off the Mac GUI last
time?  Turns out there was one user who couldn't live without it --
me!  So it's back, but I'm still not making any promises about keeping
it alive if Apple does something stupid in coming releases.  If you're
interested in playing with it in spite of that warning, it's available
from my website (http://www.kitp.ucsb.edu/~paxton/Tioga-1.5.dmg).

	Cheers, Bill

    [Vincent] Version 1.5 has seen a not-so-small change inthe
structure of the tutorial, which now has local links to images. So the
images are now included in the tarball (though the -without-images
don't have them, for those who have sparse disk space or
bandwidth). To get a local copy of the tutorial, just run rdoc and
then link doc/images to images using the following commands:

cd doc; ln -s ../images .

There are just a few new functions this time: 
  * FigureMaker#create_figure_temp_files has been made part of the public 
interface of tioga, it produces only the intermediate pdf and TeX files but 
doesn't run pdflatex (used by ctioga)
  * a Function#derivative method has been added, that does what you think it 
does.

The C code has been heavily tweaked to prevent segfaults on some
architectures/distributions, and some samples were added, notably one
for insets (I'll let you find it !).

	Cheers, Vincent

--------------------------

    Version 1.4 is a major overhaul with particular emphasis on the
tioga user interface.  Please take a moment to go through the new
section of the tutorial titled, CommandLine.  It gives a detailed
discussion of the new tioga command line interface that replaces
irb_tioga and the old mac gui.  There is a also new small
drag-and-drop application for the Mac called "Tioga Droplet" that
takes any file dropped on it and sends it to the new tioga command
line interface to have a portfolio created and displayed.  There is
also a browser-based viewer called Vtioga that JJ Fleck has developed
that uses command line tioga to create pdfs, converts them to png's,
and displays them in a browser page using Ruby on Rails.  And Vincent
Fourmond has of course been continuing his development of Ctioga.  So
there are now several nice options available for tioga user
interfaces.  [BTW: The old mac gui for tioga is now an orphan; I've
decided I can't commit to giving it the amount of attention it seems
to need to stay healthy!  The current upheaval in the user interface
area is a result of my decision that things needed to get simpler.  If
you've become hopelessly addicted to the old mac gui, I'll happily let
you adopt it.  Just let me know, and it's yours to maintain and
develop as long as your sanity lasts.]

    If you take a look in tioga/samples/plots, you will find a new
item: plot_styles.rb.  Do you like to use a sans-serif font for your
plots?  Then 'require plot_styles.rb' in your plot file, 'include
MyPlotStyles' in your plot class (the module defined in
plot_styles.rb), and call the 'sans_serif_style' method at the
beginning of your plot definition (or from your enter_page function,
or from your plot class initialization method).  Curious about what
tioga attributes there are for dealing with the appearance of plots?
Scan through the set_default_plot_style method in plot_styles.rb.
Want a style that's not in plot_styles.rb?  Great!  Write it yourself,
and share it with the rest of us by sending a message to tioga-users!

Additionnally, some more classical functionalities have been added: 
  * show_arrow now allows to specify a 'line_style' and justification for
  the markers, see the plot samples/figures/figures.rb: Arrows_second_take
  * a function Dvector.write has been added that does exactly the
  reverse of Dvector.(fancy_)read.

--------------------------	

	  Version 1.3.1 is as usual a bug-fix release, although bugs
were not that obvious this time. Among other things,
  * it fixes some troubles with IRB and the Mac GUI
  * it fixes the use of Tioga custom colors in the LaTeX materials,
  such as in one of the figures in samples/figures/figures.rb. 
  * quite a bit of code cleaning
  * some documentation updates
  * and, last but not least, the samples/ directory now contains a shell
  script to create and optionally display all the figures defined in
  one IRB Tioga ruby file. If, say, you can use gv to view PDFs, try
  out the following line:

  cd samples; ./make_plots --viewer gv figures/figures.rb
  
  Enjoy !!

	--Vincent
	
		Vincent has added a #primitive method to Function (during breaks from
writing his thesis).

    	There is a new contour algorithm.  Thank you to Roy Mayfield for telling me about the
Gri contour following routine (http://gri.sourceforge.net/).  Tioga's make_contour method now
uses that as its default;  the previous algorithm, CONREC, is still available as an option.
However, the new one seems superior -- especially if you'd like to be able to fill the contour
rather than simply stroke it.  In addition, you can optionally provide it with a "mask" of flags
indicating which entries in the table are valid for use in forming the contours.  Neat stuff.

--------------------------
	
		Version 1.3.0 will automatically remove the tex temporary files it creates
(unless the autocleanup attribute is set false).  Commands that used to have
"preview" in their names have been renamed to remove it.  For example, the
old tex_preview_fontfamily is now called tex_fontfamily.  (The old names are
actually still around for backward compatibility, but we won't be mentioning
them anymore!)  Some other commands have gone away completely since they 
have been made obsolete by the new approach of page layout using the
enter page function.  As a reminder, here's what I wrote in a recent email 
about the change in my model of what Tioga is really doing:

      In the "old days", I thought of Tioga as producing intermediate files 
      (the *_figure.tex and *_figure.txt files) that would at some later time 
      be combined by TeX to create a figure in a TeX document.  So, in that view, 
      the "final" figure PDF was created by TeX as part of typesetting a document.  
      However, I naturally wanted to see what the figure looked like while I was 
      debugging it, and so there was a "preview" ability in Tioga as well.  And 
      before long it became clear that I was looking at things in the "wrong" way.

      So there was a reversal in my image, and now I think of the process as Tioga 
      producing the final PDF for the figure and, as part of that, calling TeX as 
      a subroutine to get the job done.  Then the figure PDF can be used however 
      you wish -- as part of a TeX document of course, but for anything else as 
      well.  There is no longer any need for a "preview" and the *_figure files 
      can be deleted immediately since they're now just temporaries created to 
      drive TeX.

      There wasn't too much needed to provide better support for this new view 
      of things.  Mainly, you need to be able to specify exact sizes for figure 
      and fonts.

      Now for specifics.  Please take a quick look at tioga samples/plots/plots.rb 
      that is part of the download.   At the end of the initialize routine, at line 63, 
      there is a new addition:

              t.def_enter_page_function { enter_page }

      This tells tioga that whenever it is about to create a new PDF page, it should 
      call the 'enter_page' method which is defined in the next few lines of the file:

          def enter_page
              t.page_setup(11*72/2,8.5*72/2)
              t.set_frame_sides(0.15,0.85,0.85,0.15) # left, right, top, bottom in page coords       
          end

      The page_setup routine takes the desired width and height in "big points" (72 per inch).
      So in this case, the PDF will be 5.5 inches wide and 4.25 inches high.  The set_frame_sides 
      routine takes fractional positions on the page (i.e., page coordinates).  If you wanted 
      to change the fonts, you could do that in the enter_page routine as well by adding a 
      line like this:

              t.set_default_font_size(14)

      I hope this helps to clarify things.

	--Bill

--------------------------

	Version 1.2.1 is as usual a bug-fix release fixing some installation problems...

--------------------------

	Version 1.2.0 brings in a lot of new features. First and most important, we came up with a
proper design for a real-size scheme. Now, you can use the page_setup function to ask Tioga to
produce a preview PDF of the exact size requested, so that you can include the PDF directly in
your documents (not only LaTeX, then). A whole bunch of debugging tools have been added: you can
now set tracing tools with the (enter|exit)_(show_plot|subplot|subfigure) functions. As usual,
there is a whole bunch of small improvements and new functions to Dvector and Function.

--------------------------

	Version 1.1.7 fixes a nasty runtime bug on MacOS X.

--------------------------

	Version 1.1.6 provides marshalling for Dtable and Dvector. You can now use Marshal.dump and
Marshal.load with Dvectors. Dvectors and Function now have a bounds function, which return both the
minima and the maxima. Ruby is no longer complaining about Tioga when used with the -w switch.

--------------------------

	Version 1.1.5 is a bug-fix release - updated to the latest mkmf2.rb to make sure all
necessary files are generated during make.

--------------------------

	Version 1.1.4 is a bug-fix release - a nasty symbol clash was preventing Tioga from running
on MacOS X.3. This should now be fixed. Moreover, the load time should improve a little bit on few 
architectures.

--------------------------

	Version 1.1.3 provides a better integration of output within LaTeX
documents. A tioga.sty file is now available, with many macros for figure
inclusion and color names like the ones provided by Tioga.

	The Dobjects module is proud to announce the birth of the latest
class, Function, which provides basic interpolation and sorting for sets of
X,Y data. Not many features for now, but there's room for plenty more work.

	Dvector provides a few more functions:
		clear?, dirty?, dirty= (to check if a vector has been modified)
		min_gt, max_lt (extrema with conditions)
		set (mass modification of Dvector)

	FigureMaker has now functions for coordinate conversions:
		convert_inches_to_output, convert_output_to_inches,
		convert_mm_to_output, convert_output_to_mm

--------------------------

	Version 1.1.2 provides more complete control over page layout and font
selection.  Here's a list of new features:

		for top-level page layout
			set_device_pagesize(width, height) # measured in tenths of points
			set_A4_portrait, set_A4_landscape
			set_A5_portrait, set_A5_landscape
			set_B5_portrait, set_B5_landscape
			set_JB5_portrait, set_JB5_landscape
			set_USLegal_portrait, set_USLegal_landscape
			set_USLetter_portrait, set_USLetter_landscape
			set_frame_sides(left, right, top, bottom) # sizes in page coords [0..1]

		for TeX preview page and figure size
			tex_preview_paper_width
			tex_preview_paper_height
			tex_preview_hoffset
			tex_preview_voffset
			tex_preview_figure_width
			tex_preview_figure_height

		for TeX preview font selection
			tex_preview_fontsize
			tex_preview_fontfamily
			tex_preview_fontseries
			tex_preview_fontshape

--------------------------

	Version 1.1.1 is the first Tioga to be called a "beta" release.  You can
interpret that anyway you'd like, but to me it means Tioga has been around long
enough and had enough use to justify inviting more folks to give it a try.
The "alpha" label is a warning to "proceed at your own risk", and only brave
souls go ahead when they see that.  I think Tioga has gotten stable enough
that we can drop the "threat level" down a notch.  (Fingers crossed of course!)

--------------------------

	Version 1.1.0 splits off the Dvector & Dtable modules from the FigureMaker so
that they can be used in other packages (Vincent Fourmond both suggested this and
did the work to make it happen).

--------------------------

    Version 1.0.M no longer raises error for calls on 'stroke', 'fill', and such with an empty path.
It has also been reconfigured to support the new Mac GUI which now works with both PowerPC and Intel
processors.

--------------------------

    Version 1.0.L adds 'transparency' as a synonym for (1.0 - opacity).  So
now you can set 'fill_transparency' to 0.3 instead of setting 'fill_opacity'
to 0.7.  I'm sure that makes your day.  The documentation has also been
updated of course.

--------------------------

    Version 1.0.K was Vincent Fourmond's fault!  The same day that J was released,
he sent me an email pointing out an oversight in the legend functionality.
Not only that, he sent along an implementation to fix the problem!  What could I do?
I had to put it in and make a new release.  So thanks to Vincent, you can now include 
markers on the lines in legends.  Details in the new documentation for 'save_legend_info'.

?? 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
Loading complete
