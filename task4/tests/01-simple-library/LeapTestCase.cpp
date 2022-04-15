//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST(LeapTestCase, test1) {
      EXPECT_THROW (IsLeap(-1), std::invalid_argument);
      EXPECT_THROW (IsLeap(0), std::invalid_argument);
      EXPECT_NO_THROW (IsLeap(1994));

      EXPECT_EQ (IsLeap(1), false);
      EXPECT_EQ (IsLeap(4), true);
      EXPECT_EQ (IsLeap(400), true);
      EXPECT_EQ (IsLeap(100), false);
}

TEST(GetMDTestCase, test1) {
      EXPECT_EQ (GetMonthDays(1904, 2), 29);
      EXPECT_EQ (GetMonthDays(1900, 2), 28);

      EXPECT_THROW (GetMonthDays(1904, 13), std::invalid_argument);
      EXPECT_NO_THROW (GetMonthDays(1904, 12));

      EXPECT_EQ (GetMonthDays(1904, 4), 30);
      EXPECT_EQ (GetMonthDays(1904, 5), 31);
}
