#include <Python.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

static PyObject * 
c_func(PyObject *self, PyObject *args)
{
	int a,b; 
	
	if(!PyArg_ParseTuple(args, "ii", &a, &b)) 
		return NULL;
	else
	{ 
		
		return PyString_FromFormat("this is returned from C!!!\nYou inputted %d and %d\na^2 = %d  b^2 = %d",a,b,a*a,b*b);
	}

}

static PyMethodDef cdemoMethods[] = 
{
 	{"cFunc",  c_func, METH_VARARGS, "a function docstring"},
  {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initcDemo(void)
{
	(void) Py_InitModule("cDemo", cdemoMethods);
}