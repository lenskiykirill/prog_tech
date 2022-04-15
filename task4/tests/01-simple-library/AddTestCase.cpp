//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST_F(AddTestCase, test1) {
      EXPECT_EQ (Add(1, -1), 0);
      EXPECT_EQ (Add(1, 1), 2);
      EXPECT_EQ (Add(-1, -1), -2);
}
