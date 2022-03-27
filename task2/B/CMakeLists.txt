cmake_minimum_required (VERSION 2.8)

project (prog_tech)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../lib/)

add_library ("lib" SHARED ${PROJECT_SOURCE_DIR}/lib.cpp)
