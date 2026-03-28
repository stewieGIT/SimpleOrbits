#ifndef MODULE_H
#define MODULE_H

#include <Python.h>

// height in m
#define R 6371e3
#define MU 3.984e14
#define KM 1e3

PyObject *py_calc_circular_vel(PyObject *self, PyObject *args);
PyObject *py_vector_add(PyObject *self, PyObject *args);

#endif
