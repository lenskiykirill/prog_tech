//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>

class TreeTestCase : public ::testing::Test {
      using path = std::filesystem::__cxx11::path;

      protected:
      
      path tmp_path;
      path tmp_file;
      path tmp_dir;
      path tmp_subdir;

            void SetUp() {
                  tmp_path = std::filesystem::temp_directory_path();

                  tmp_dir = tmp_path/"test_Tree_dir";
                  std::filesystem::create_directory(tmp_dir);

                  tmp_file = tmp_dir/".filename";

                  std::ofstream out(tmp_file);
                  out << "Hello, world!\n";
                  out.close();

                  tmp_subdir = tmp_dir/"subdir";
                  std::filesystem::create_directory(tmp_subdir);
            }

            void TearDown() {
                  std::filesystem::remove_all(tmp_dir);
            }
};
