cmake_minimum_required (VERSION 2.8)
project (blue_flame) # blue_flame -- синее пламя, которым горит cmake

execute_process(COMMAND python3 ${PROJECT_SOURCE_DIR}/A/preparing.py
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A/)

add_subdirectory (${PROJECT_SOURCE_DIR}/B/)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

target_include_directories (C ${PROJECT_SOURCE_DIR})
#include_directories (${PROJECT_SOURCE_DIR})

add_executable (C ${PROJECT_SOURCE_DIR}/C/main.cpp )

target_link_libraries (C lib)

enable_testing()
find_package (GTest REQUIRED)

add_executable (CTest ${PROJECT_SOURCE_DIR}/C/test.cpp) # ${PROJECT_SOURCE_DIR}/C/test.cpp)

add_library (testing STATIC ${PROJECT_SOURCE_DIR}/C/test.cpp)

target_link_libraries(CTest GTest::GTest GTest::Main lib testing)
