#include <gmock/gmock.h>
#include <gtest/gtest.h>
using ::testing::_;

#include "mock/mock_mystr.h"

extern "C" {
#include "sub.h"
}

MockMystr* mystr_mock;

class StrTest : public ::testing::Test {

  protected:
    virtual void SetUp()
    {
        printf("SetUp\n");
        mystr_mock = new MockMystr();
    }

    virtual void TearDown()
    {
        printf("TearDown\n");
        delete mystr_mock;
    }
};

int main(int argc, char** argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST_F(StrTest, test01)
{
    const char* test_str = ": test";
    int test_str_len = strlen(test_str);
    EXPECT_CALL(*mystr_mock, str_analyze(_, _))
        .WillOnce(::testing::Return(test_str_len));
    EXPECT_EQ(test_str_len, test1(test_str));
}
TEST_F(StrTest, test02)
{
    const char* test_str = ": test2";
    int test_str_len = strlen(test_str);
    EXPECT_CALL(*mystr_mock, str_analyze(_, _))
        .WillOnce(::testing::Return(test_str_len))
        .RetiresOnSaturation();
    EXPECT_EQ(test_str_len, test1(test_str));
}


