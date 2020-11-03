#include <iostream>
#include <cstdlib>
#include <string>
#include <boost/python.hpp>
#include <boost/filesystem.hpp>

using namespace std;
namespace python = boost::python;
namespace fs = boost::filesystem;

int main(int argc, char* argv[]) {
  fs::path exe_path(argv[0]);
  cout << exe_path << endl;
  fs::path exe_dir = exe_path.parent_path();
  cout << exe_dir << endl;
  
  string dir = fs::read_symlink("/proc/self/exe").parent_path().string();
  cout << dir << endl;
  
  //setenv("PYTHONPATH", ".", 1);
  //PyRun_SimpleString("import sys\nsys.path.append(\"/home/dagothar/test/pyboost/build\")");
  Py_Initialize();
  //PyRun_SimpleString("import sys\nsys.path.append(\"/home/dagothar/test/pyboost/build\")");
  PyRun_SimpleString(("import sys\nsys.path.append(\"" + dir + "\")").c_str());
  
  python::object my_module = python::import("sample_module");
  python::object foo = my_module.attr("sample_function");
  python::object res = foo(5.0);
  float y = python::extract<float>(res);
  cout << y << endl;
  
  //Py_Finalize();
  return 0;
}
