#include <iostream>
#include <cstdlib>
#include <string>
#include <boost/python.hpp>
#include <boost/filesystem.hpp>

using namespace std;
namespace python = boost::python;
namespace fs = boost::filesystem;

int main(int argc, char* argv[]) {
  string exe_dir = fs::read_symlink("/proc/self/exe").parent_path().string();
  
  string module_path = exe_dir + "/../scripts";
  cout << module_path << endl;
  
  Py_Initialize();
  PyRun_SimpleString(("import sys\nsys.path.append(\"" + module_path + "\")").c_str());
  
  python::object sample_module = python::import("sample_module");
  python::object sample_function = sample_module.attr("sample_function");
  python::object result = sample_function(5.0);
  float y = python::extract<float>(result);
  cout << y << endl;
  
  return 0;
}
