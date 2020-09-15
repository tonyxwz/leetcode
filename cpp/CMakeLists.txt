# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("cpp")

# Include sub-projects.


# add subdirectories
add_executable(learn "src/threads.cc")
