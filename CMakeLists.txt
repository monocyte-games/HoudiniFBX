cmake_minimum_required(VERSION 3.6)

project(ROP_FBX)

set(HOUDINI_ROOT $ENV{HOUDINI_ROOT} CACHE FILEPATH "Houdini Installation Directory")

# CMAKE_PREFIX_PATH must contain the path to the toolkit/cmake subdirectory of
# the Houdini installation. See the "Compiling with CMake" section of the HDK
# documentation for more details, which describes several options for
# specifying this path.
list(APPEND CMAKE_PREFIX_PATH "${HOUDINI_ROOT}/toolkit/cmake")

add_subdirectory("src")