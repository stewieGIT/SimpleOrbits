#ifndef MODULE_H
#define MODULE_H

#include <Python.h>
#include <structmember.h>

// height in m
#define R 6371e3
#define MU 3.984e14
#define KM 1e3

PyObject *calc_circular_vel(PyObject *self, PyObject *args);
PyObject *vec3_add(PyObject *self, PyObject *args);

typedef struct {
	PyObject_HEAD
	double x;
	double y;
	double z;
} vec3;

PyMemberDef vec3_members[];
int vec3_init(vec3 *self, PyObject *args, PyObject *kwds);
void vec3_dealloc(vec3 *self);
PyObject *vec3_repr(PyObject *op);
PyTypeObject PyVec3;

#endif
