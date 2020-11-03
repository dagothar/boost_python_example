cmake_minimum_required(VERSION 3.0)
project(pyboost)

set(CMAKE_CXX_STANDARD 11)

find_package(PythonLibs REQUIRED)
find_package(Boost REQUIRED COMPONENTS python filesystem)

include_directories(
  ${PYTHON_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

link_directories(
  ${PYTHON_LIBRARY_DIRS}
)

add_executable(pb test.cpp)
target_link_libraries(pb ${PYTHON_LIBRARIES} -lboost_system -lboost_filesystem -lboost_python-py36)
