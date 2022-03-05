#include "gtest/gtest.h"

TEST(SampleTestName, PassingSampleTestCaseName)
{
    ASSERT_EQ(0, 0);
}

TEST(SampleTestName, FailingSampleTestCaseName)
{
    ASSERT_EQ(0, 1);
}
