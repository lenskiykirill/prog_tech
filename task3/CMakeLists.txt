cmake_minimum_required(VERSION 3.0)

if (CMAKE_INSTALL_PREFIX)
      set(CMAKE_SKIP_BUILD_RPATH FALSE)
      set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

      set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
      set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()

if (ARM_BUILD STREQUAL "ON")

      unset (CMAKE_SYSTEM_NAME)
      unset (CMAKE_SYSTEM_PROCESSOR)

      #unset (CMAKE_C_COMPILER)
      #unset (CMAKE_CXX_COMPILER)

      set (CMAKE_SYSTEM_NAME Linux)
      set (CMAKE_SYSTEM_PROCESSOR arm)

      set (TOOLCHAIN "" CACHE FILEPATH "toolchain")

      set (CMAKE_C_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-gcc)
      set (CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
      
      set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
      set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
      set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
      set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

      message (${CMAKE_CXX_COMPILER})
endif()

project(SimpleLibrary)

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)

add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

if (CMAKE_INSTALL_PREFIX)
      #      set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
      #      set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

      install (TARGETS Main MainLib buffer
               RUNTIME DESTINATION bin
               LIBRARY DESTINATION lib)
      

endif()

target_link_libraries(MainLib buffer)
