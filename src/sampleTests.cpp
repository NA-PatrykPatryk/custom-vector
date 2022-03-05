#include "gtest/gtest.h"
#include "OurVector.hpp"


TEST(VectorTest, sizeMethodShouldReturn0WhenClassInitialized) 
{
    OurVector<int> sut;
    ASSERT_EQ(sut.size(), 0);
}

TEST(VectorTest, whenInitilializedVecotorCapacityEqualTen) 
{
    OurVector<int> sut;

    ASSERT_EQ(sut.capacity(), 10);
}


TEST(VectorTest, whenIntisPushBackItsOnVectorIndex0) 
{
    OurVector<int> sut;
        sut.pushBack(1);
    ASSERT_EQ(sut.at(0), 1 );
}




