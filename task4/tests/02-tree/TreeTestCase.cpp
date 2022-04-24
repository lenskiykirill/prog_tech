//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <iostream>

TEST_F (TreeTestCase, test1) {
      EXPECT_THROW (GetTree("/?/?/?", false), std::invalid_argument);
      EXPECT_THROW (GetTree(std::string(tmp_file), true), std::invalid_argument);
}

TEST_F (TreeTestCase, test2) {
      FileNode fn_1, fn_2;

      fn_1.name = fn_2.name = std::string("file");
      fn_1.is_dir = fn_2.is_dir = true;

      fn_1.children = std::vector<FileNode>();
      fn_2.children = std::vector<FileNode>();

      EXPECT_EQ (operator==(fn_1, fn_2), true);
      fn_1.name = "elif";

      EXPECT_EQ (operator==(fn_1, fn_2), false);
}

TEST_F (TreeTestCase, test3) {
      
      FileNode test_ans;
      test_ans.name = tmp_dir.filename().string();
      test_ans.children = std::vector<FileNode> (1, {tmp_subdir.filename().string(), true, {}});
      test_ans.is_dir = true;

      EXPECT_EQ (GetTree(std::string(tmp_dir),true), test_ans);

      test_ans.children.clear();

      test_ans.children.push_back ({tmp_file.filename().string(), false, {}});
      test_ans.children.push_back ({tmp_subdir.filename().string(), true, {}});
      EXPECT_EQ (GetTree(std::string(tmp_dir),false), test_ans);
}

TEST_F (TreeTestCase, test4) {
      FileNode test_ans;

      test_ans.name = tmp_dir.filename().string();
      test_ans.children = std::vector<FileNode> (1, {tmp_file.filename().string(), false, {}});
      test_ans.is_dir = true;

      FileNode ans = GetTree(tmp_dir.string(), false);
      
      FilterEmptyNodes(ans, tmp_dir.string());

      EXPECT_EQ (GetTree(tmp_dir.string(), false), test_ans);
}
