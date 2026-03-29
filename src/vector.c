#include "vector.h"
#include "module.h"

PyMemberDef vec3_members[] = {
	{"x", T_DOUBLE, offsetof(vec3, x), 0, "x coordinate"},
	{"y", T_DOUBLE, offsetof(vec3, y), 0, "y coordinate"},
	{"z", T_DOUBLE, offsetof(vec3, z), 0, "z coordinate"},
	{NULL}
};

int vec3_init(vec3 *self, PyObject *args, PyObject *kwds)
{
	char *kwlist[] = {"x", "y", "z", NULL };

	self->x = 0.0;
	self->y = 0.0;
	self->z = 0.0;

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|ddd", kwlist,
				&self->x, &self->y, &self->z))
		return -1;

	return 0;
}

void vec3_dealloc(vec3 *self)
{
	Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *vec3_repr(PyObject *op)
{
	vec3 *self = (vec3 *)op;
	PyObject *format = PyUnicode_FromString("vec3(x=%f, y=%f, z=%f)");

	PyObject *args = Py_BuildValue("(ddd)", self->x, self->y, self->z);

	PyObject *repr = PyUnicode_Format(format, args);
	
	Py_DECREF(format);
	Py_DECREF(args);

	return repr;
}

PyTypeObject PyVec3 = {
	.ob_base = PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "sorbits.vec3",
	.tp_init = (initproc)vec3_init,
	.tp_dealloc = (destructor)vec3_dealloc,
	.tp_basicsize = sizeof(vec3),
	.tp_itemsize = 0,
	.tp_flags = Py_TPFLAGS_DEFAULT,
	.tp_doc = PyDoc_STR("Vector object that contains x, y and z coordinates"),
	.tp_new = PyType_GenericNew,
	.tp_members = vec3_members,
	.tp_repr = (reprfunc)vec3_repr
};


