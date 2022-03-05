#include "gtest/gtest.h"
#include "OurVector.hpp"
#include <stdexcept>


struct VectorTest:public ::testing::Test
{
    OurVector<int> vectorTest;
};



TEST_F(VectorTest, sizeMethodShouldReturn0WhenClassInitialized) 
{
    EXPECT_EQ(vectorTest.size(), 0);
}

TEST_F(VectorTest, whenInitializedVectorCapacityEqualTen) 
{
    EXPECT_EQ(vectorTest.capacity(), 10);
}

TEST_F(VectorTest, whenIntisPushBackItsOnVectorIndex0) 
{
    vectorTest.pushBack(1);
    EXPECT_EQ(vectorTest.at(0), 1);
}

TEST_F(VectorTest, whenInitializedWithSizeEqual5SizeShouldReturn5)
{
    int vecSize{ 5 };
    OurVector<int> sut(vecSize);
    EXPECT_EQ(sut.size(), vecSize);
}

TEST_F(VectorTest, whenInitializedWithSize1AndValue5ShouldReturn5)
{
    int vecSize{1};
    int vecValue{5};
    OurVector<int> sut(vecSize, vecValue);
    EXPECT_EQ(sut.at(0), vecValue);
}

TEST_F(VectorTest, whenUsingAtOutOfScopeShouldThrowExcept)
{
    ASSERT_THROW(vectorTest.at(6),std::out_of_range);
}

TEST_F(VectorTest, whenCapacity)
{
    vectorTest.pushBack(2);
    vectorTest.pushBack(2);
    vectorTest.pushBack(2);
    vectorTest.pushBack(2);
    vectorTest.pushBack(2);
    vectorTest.pushBack(2);
    vectorTest.pushBack(2);
    vectorTest.pushBack(2);
    vectorTest.pushBack(2);
    vectorTest.pushBack(2);
    vectorTest.pushBack(2);
    vectorTest.pushBack(2);
    EXPECT_EQ(vectorTest.size(),12);
    EXPECT_EQ(vectorTest.capacity(),15);
}