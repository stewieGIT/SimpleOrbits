#include <stdio.h>
#include <math.h>
#include "module.h"

static PyMethodDef sorbits_methods[] = {
	{"calculate_circular_vel", py_calc_circular_vel, METH_VARARGS, "Calculate circular orbit velocity given an height in km"},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef orbits_module = {
    PyModuleDef_HEAD_INIT,
    "sorbits",
    "Python interface that allows different orbit calculations",
    -1,
    sorbits_methods
};

PyMODINIT_FUNC PyInit_sorbits(void) {
    return PyModule_Create(&orbits_module);
}

int main(void) {
	return 0;
}
