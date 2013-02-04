python_tutorial
===============

Python tutorial for Space@VT Grad seminar

**Authors:** 	 
		AJ Ribeiro    
		Nathaniel A. Frissell    
		Sebastien de Larquier    

### Content
* Repository content
* Python install instructions
* Running this code
* Setting-up a IPython Notebook server (on Ubuntu) -- just for fun

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

#### Ubuntu

    apt-get install -y python2.7 python-pip ipython
    pip install --upgrade ipython
    apt-get install -y ipython-notebook ipython-qtconsole
    apt-get install -y python-scipy python-matplotlib python-mpltoolkits.basemap python-h5py

Note: aptitude does not install the latest version of basemap yet. For a more up-to-date version, go on the basemap website and follow install instructions.

### SpacePy on Ubuntu
Take care of dependencies:

    apt-get install -y easy_install
    easy_install networkx
    apt-get install -y gfortran
    apt-get install -y python-numpy-dbg # (Maybe needed, maybe not)
    easy_install ffnet
    apt-get install libncurses5-dev # (Needed for NASA CDF)

You also need the NASA CDF library:
Download tar.gz file from http://cdf.gsfc.nasa.gov/
Follow instructions in README.install.  In summary:

    make OS=linux ENV=gnu all
    make test # (Optional step... just makes sure everything is working!)
    make INSTALLDIR=/usr/local/cdf install # (Feel free to change the install directory if you like.)
    # Source /usr/local/cdf/bin/definitions.B in your .bashrc file!!

Now go download SpacePy from http://spacepy.lanl.gov/.  They have good instructions, but
if you did everything above, you should be able to just run their install script and it
should be good to go:

    python setup.py install

#### Other distributions

Most linux distributions come with package managers (like aptitude for Ubuntu, or Yum for Fedora). Use it to install python.
  
  
### MacOS

We strongly recommend using [MacPorts](http://www.macports.org/). Using MacPorts you can run the following lines to install python and useful modules.

    ver=27
    port install python${ver}
    port install py${ver}-ipython
    port install py${ver}-numpy
    port install py${ver}-matplotlib
    port install py${ver}-matplotlib-basemap
    port install py${ver}-scipy
    port install py${ver}-h5py
    port install py${ver}-tornado
    port install py${ver}-zmq
    port install py${ver}-pil


### Windows

Unfortunately, although python runs on windows, it is poorly supported and requires a lot of patience to install...

1.  Download and install Python 2.7 from http://www.python.org/download/
2.  Add c:\Python and c:\Python27\Scripts (or wherever you installed Python) 
			to your environment variables
3.  Follow the instructions to install setuptools from http://pypi.python.org/pypi/setuptools
4.  the rest of the packages can be installed using easy_install.exe from the windows command prompt, E.G.  easy_install.exe ipython

	if at any point you are told that another package is needed, use easy_install.exe to install it
			
NOTES:
* If your install fails, look into manually installing the binaries ([http://www.lfd.uci.edu/~gohlke/pythonlibs/](http://www.lfd.uci.edu/~gohlke/pythonlibs/))
* In order to build and install the C extension library, you must install Microsoft Visual C (MSVC)



## Running this code

To open IPython notebooks (*.ipynb), simply start the notebook interface in this directory, or start it anywhere then drag and drop the notebooks in your browser.
  
To start IPython notebook, run

    $ ipython notebook --pylab=inline

To run *.py files, execute

    $ python your_script.py

or from an IPython console

    $ run your_script.py



## Setting-up an IPython Notebook server (on Ubuntu)

This is a bonus step for more advanced use of IPython.
Assuming you have installed all of the above, follow these instructions to set-up a notebook server (adapted from [here](http://ipython.org/ipython-doc/rel-0.13.1/interactive/htmlnotebook.html)).

First create a nbserver ipython profile

    $ ipython profile create nbserver

Then start an ipython session

    $ ipython

And create a hashed password using

    In [1]: from IPython.lib import passwd
    In [2]: passwd()
    Enter password:
    Verify password:
    Out[2]: 'sha1:67c9e60bb8b6:9ffede0825894254b2e042ea597d771089e11aed'

Then exit ipython and run

    $ openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout ipycert.pem -out ipycert.pem
    $ sudo mv ipycert.pem /etc/ssl/certs/ipycert.pem

Then open the ~/.config/ipython/profile_nbserver/ipython_notebook_config.py and add the following lines

    c = get_config()

    # Kernel config
    c.IPKernelApp.pylab = 'inline'  # if you want plotting support always

    # Notebook config
    c.NotebookApp.certfile = u'/etc/ssl/certs/ipycert.pem'
    c.NotebookApp.ip = '*' # Replace '*' with your IP (i.e., sd-work0.ece.vt.edu)
    c.NotebookApp.open_browser = False
    c.NotebookApp.password = u'sha1:bcd259ccf...your hashed password here'
    # It's a good idea to put it on a known, fixed port
    c.NotebookApp.port = 9999
    
    # Add this for auto-reload
    # lines of code to run at IPython startup
    c.IPKernelApp.exec_lines = [
    	'%load_ext autoreload', 
    	'%autoreload 2'
    ]

To start the notebook, I recommend you create an alias. Open your ~/.bashrc file and add the following line

    alias ipython-server='ipython notebook --profile=nbserver'
    
Finally restart your terminal or source your bashrc.

Now you just have to start the notebook server from the directory where you want your notebooks to be stored. 
CD into the desired directory and run

    $ ipython-server&
    
You should see a message telling you your notebook server has been started and is accessible at https://your.ip.address:9999.
You will have to accept the certificate (as it is self-signed), and enter your password. Then you are good to go!
