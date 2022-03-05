#include "gtest/gtest.h"
#include "OurVector.hpp"


struct VectorTest:public ::testing::Test
{
    OurVector<int> vectorTest;
};



TEST_F(VectorTest, sizeMethodShouldReturn0WhenClassInitialized) 
{
    ASSERT_EQ(vectorTest.size(), 0);
}

TEST_F(VectorTest, whenInitializedVectorCapacityEqualTen) 
{
    ASSERT_EQ(vectorTest.capacity(), 10);
}

TEST_F(VectorTest, whenIntisPushBackItsOnVectorIndex0) 
{
    vectorTest.pushBack(1);
    ASSERT_EQ(vectorTest.at(0), 1);
}

TEST_F(VectorTest, whenInitializedWithSizeEqual5SizeShouldReturn5)
{
    int vecSize{ 5 };
    OurVector<int> sut(vecSize);
    ASSERT_EQ(sut.size(), vecSize);
}

TEST_F(VectorTest, whenInitializedWithSize1AndValue5ShouldReturn5)
{
    int vecSize{1};
    int vecValue{5};
    OurVector<int> sut(vecSize, vecValue);
    ASSERT_EQ(sut.at(0), vecValue);
}