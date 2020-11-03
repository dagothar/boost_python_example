cmake_minimum_required(VERSION 3.0)
project(boost_python_example)

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

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(example src/example.cpp)
target_link_libraries(example ${PYTHON_LIBRARIES} -lboost_system -lboost_filesystem -lboost_python-py36)
