#include "module.h"

static int custom_module_exec(PyObject *m)
{
	if (PyType_Ready(&PyVec3) < 0)
	{
		return -1;
	}

	if (PyModule_AddObjectRef(m, "vec3", (PyObject*) &PyVec3) < 0)
	{
		return -1;
	}

	return 0;
}

static PyModuleDef_Slot sorbits_slots[] = {
	{Py_mod_exec, custom_module_exec},
	{Py_mod_multiple_interpreters, Py_MOD_MULTIPLE_INTERPRETERS_NOT_SUPPORTED},
	{0, NULL}
};

static PyMethodDef sorbits_methods[] = {
	{"calculate_circular_vel", calc_circular_vel, METH_VARARGS, "Calculate circular orbit velocity given an height in km"},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef orbits_module = {
    PyModuleDef_HEAD_INIT,
    .m_name = "sorbits",
    .m_doc = "Python interface that allows different orbit calculations",
    .m_size = 0,
    .m_methods = sorbits_methods,
	.m_slots = sorbits_slots
};

PyMODINIT_FUNC PyInit_sorbits(void) {
    return PyModuleDef_Init(&orbits_module);
}

int main(void) {
	return 0;
}
