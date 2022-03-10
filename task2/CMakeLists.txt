cmake_minimum_required (VERSION 2.8)
project (blue_flame) # blue_flame -- синее пламя, которым горит cmake

execute_process(COMMAND python3 ${PROJECT_SOURCE_DIR}/A/preparing.py
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A/)

add_subdirectory (${PROJECT_SOURCE_DIR}/B/)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

include_directories (${PROJECT_SOURCE_DIR}/A)
include_directories (${PROJECT_SOURCE_DIR}/B)

add_executable (C ${PROJECT_SOURCE_DIR}/C/main.cpp)

target_link_libraries (C lib)
