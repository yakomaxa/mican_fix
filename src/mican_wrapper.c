#define PY_SSIZE_T_CLEAN
#include "Python.h"

extern int mican(const char *pdb1, const char *pdb2);

static PyObject* mican_mican(PyObject* self, PyObject* args, PyObject* kw)
{
  const char* pdb1 = NULL;
  const char* pdb2 = NULL;
  static char* argnames[] = {"pdb1", "pdb2", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kw, "|ss",
				   argnames, &pdb1, &pdb2))
    return NULL;
  mican(pdb1, pdb2);
  return Py_BuildValue("");
}


//definition of all methods of my module
static PyMethodDef micanmethods[] = {
  {"mican_mican", (PyCFunction)mican_mican, METH_VARARGS | METH_KEYWORDS},
  {NULL},
};

// hello module definition struct
static struct PyModuleDef mymican = {
  PyModuleDef_HEAD_INIT,
  "mymican",
  "Python3 C API Module(Sample 1)",
  -1,
  micanmethods
};

//module creator
PyMODINIT_FUNC PyInit_mymican(void)
{
  return PyModule_Create(&mymican);
}
