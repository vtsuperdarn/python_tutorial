from distutils.core import setup, Extension

ext = Extension('cDemo', sources=['cDemo.c'])

setup(name='cDemo', version='1.0', description='this is a demo of c extensions', ext_modules=[ext])