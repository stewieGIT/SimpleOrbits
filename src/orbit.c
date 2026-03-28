#include "module.h"
#include "orbit.h"

double calculate_circular_vel(double height) 
{
	double h = (height * KM) + R;
	return sqrt((MU) / h);
}

PyObject *py_calc_circular_vel(PyObject *self, PyObject *args) {
	double height;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "d", &height)) {
        return NULL;
    }

	double result = calculate_circular_vel(height);

    return PyFloat_FromDouble(result);
}
