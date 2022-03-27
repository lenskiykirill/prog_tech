#include <gtest/gtest.h>
#include "B/lib.h"
#include "A/index.h"

TEST (index, simple_test) {
      ASSERT_EQ (5, fiver());
}

TEST (lib, simple_test) {
      ASSERT_EQ (5, fiver());
}
