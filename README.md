python_tutorial
===============

Python tutorial for Space@VT Grad seminar

**Authors:**: 	AJ Ribeiro
		Nathaniel A. Frissell
		Sebastien de Larquier

### Content
* Repository content
* Python install instructions
* Running this code

## Repository content
  
This repository contains IPython notebooks (*.ipynb) covering:
* Python basics
* Plotting library: matplotlib
* Scientific/Numerical library: SciPy & Numpy
* Code wrapping (C/Fortran)
* SpacePy
* A space science exemple use of Python

These notebooks mostly contain all the code needed, but some examples are directly runfrom stand-alone python scripts (*.py).

The "data" directory contains data files used as examples in the notebooks.

The "examples" directory contains more python examples (from the matplotlib gallery).


## Python install instructions

In order to run the examples provided in this repository, you will need:
* Python 2.7
* IPython
* matplotlib
* SciPy
* Numpy
* h5py
* idlsave
* SpacePy

### Linux


### MacOS


### Windows

1.  Download and install Python 2.7 from http://www.python.org/download/
2.  Add c:\Python and c:\Python27\Scripts (or wherever you installed Python) 
			to your environment variables
3.  Follow the instructions to install easy_install
4.  the rest of the packages can be installed using easy_install.exe from the windows command prompt
			E.G.  easy_install.exe ipython

			if at any point you are told that another package is needed, use easy_install.exe to install it
			
5.  In order to build and install the C extension library, you must install Microsoft Visual C



## Running this code

To open IPython notebooks (*.ipynb), simply start the notebook interface in this directory, or start it anywhere then drag and drop the notebooks in your browser.

    $ ipython notebook --pylab=inline

To run *.py files, execute

    $ python your_script.py

or from an IPython console

    $ run your_script.py


