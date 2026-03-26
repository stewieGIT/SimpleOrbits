#include <stdio.h>
#include <Python.h>
#include <math.h>

// height in m
#define R 6371e3
#define MU 3.984e14
#define KM 1e3

double calc_velocity(double height);

static PyObject *method_calc_velocity(PyObject *self, PyObject *args) {
	double height;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "d", &height)) {
        return NULL;
    }

	double result = calc_velocity(height);

    return PyFloat_FromDouble(result);
}

static PyMethodDef simple_orbits_methods[] = {
    {"calc_velocity", method_calc_velocity, METH_VARARGS, "Python method to calculate circular orbit velocity at a given height"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef simple_orbits_module = {
    PyModuleDef_HEAD_INIT,
    "sorbits",
    "Python interface that allows different orbit calculations",
    -1,
    simple_orbits_methods
};

PyMODINIT_FUNC PyInit_sorbits(void) {
    return PyModule_Create(&simple_orbits_module);
}

double calc_velocity(double height) 
{
	double h = (height * KM) + R;
	return sqrt((MU) / h);
}

int main(void) {
	return 0;
}
