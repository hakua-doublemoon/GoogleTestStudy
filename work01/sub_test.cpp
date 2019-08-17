#include <gmock/gmock.h>
#include <gtest/gtest.h>
using ::testing::_;

extern "C" {
#include "sub.h"
}

TEST(sub_test, test01)
{
    const char* test_str = ": test";
    int test_str_len = strlen(test_str);
    EXPECT_EQ(test_str_len, test1(test_str));
}

TEST(sub_test, test02)
{
    const char* test_str = ": test2";
    int test_str_len = strlen(test_str);
    EXPECT_EQ(test_str_len, test1(": test2"));
}
