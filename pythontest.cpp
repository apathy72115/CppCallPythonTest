#include<iostream>
#include</usr/include/python3.5/Python.h>
using namespace std;
void PythonExe()
{
  Py_Initialize();
  PyRun_SimpleString("print('Hello World!')\n");
  Py_Finalize();
}
void Hello()
{
	Py_Initialize();
	PyObject * pModule = NULL;
	PyObject * pFunc = NULL;
  	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('/home/proxy-1')");//當前位置 很重要！
	pModule = PyImport_ImportModule("Test001");// python file
	if (pModule == NULL) {
	  printf("ERROR importing module\n");
	  exit(-1);
	} 
	pFunc = PyObject_GetAttrString(pModule, "A");// python function
	if (pFunc == NULL) {
	  printf("ERROR getting Hello attribute\n");
	  exit(-1);
	} 
	PyEval_CallObject(pFunc, NULL);
	Py_Finalize();
}

int main()
{
  PythonExe();
  Hello();

}

