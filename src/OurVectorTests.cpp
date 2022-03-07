#include "gtest/gtest.h"
#include "OurVector.hpp"
#include <stdexcept>


struct VectorTest:public ::testing::Test
{
    OurVector<int> vectorTest;
};

TEST_F(VectorTest, whenInitializedVectorCapacityEqualZero) 
{
    EXPECT_EQ(vectorTest.capacity(), 0);
}

TEST_F(VectorTest, sizeMethodShouldReturn0WhenClassInitialized) 
{
    EXPECT_EQ(vectorTest.size(), 0);
}

TEST_F(VectorTest, WhenInitWithNegativeSizeThenDoNothing)
{
    EXPECT_THROW(OurVector<int> vec(-1), std::invalid_argument);
    EXPECT_THROW(OurVector<int> vec(-1, 2), std::invalid_argument);
}

TEST_F(VectorTest, whenInputIs6SizeShouldReturn6) 
{
    OurVector<int> vec(6);
    EXPECT_EQ(vec.size(), 6);
}

/*
TEST_F(VectorTest, WhenCapacityExtensionCalledThenCapacityIsExtended)
{
	auto capacityBeforeExtension = vectorTest.capacity();
	vectorTest.extendCapacity();
	EXPECT_TRUE(vectorTest.capacity() > capacityBeforeExtension);
}

TEST_F(VectorTest, WhenCapacityExtensionCalledThenReferenceToCapacityMinusOneIsValid) {
    OurVector<int> sut(1);
	sut.getArrRaw()[vectorTest.capacity() - 1] = 0;
	sut.extendCapacity();
	sut.getArrRaw()[vectorTest.capacity() - 1] = 0;
}
*/

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
    int vecSize{ 1 };
    int vecValue{ 5 };
    OurVector<int> sut(vecSize, vecValue);
    EXPECT_EQ(sut.at(0), vecValue);
}

TEST_F(VectorTest, WhenVectorFilledWithSixFoursExpect4AtIndex3)
{
    OurVector<int> vec(6, 4);
    EXPECT_EQ(vec.at(3), 4);
}

TEST_F(VectorTest, whenUsingAtOutOfScopeShouldThrowExcept)
{
    EXPECT_THROW(vectorTest.at(6),std::out_of_range);
}

TEST_F(VectorTest, whenUsingNegativeIndexShouldThrowExcept)
{
    EXPECT_THROW(vectorTest.at(-1),std::out_of_range);
}

TEST_F(VectorTest, vectorCanStoreDifferentDataTypes) {
    std::string testValue {"testCase"};
    OurVector<std::string> sut(1, testValue);
    EXPECT_EQ(sut.at(0), testValue);
}

TEST_F(VectorTest, whenCapacityIsOverCopyElementsToNewArray)
{
    vectorTest.pushBack(2);
    EXPECT_EQ(vectorTest.size(),1);
    EXPECT_EQ(vectorTest.capacity(),1);
}

TEST_F(VectorTest, whenVectorHasSize2ShouldHaveSize1AfterPopBack)
{
    OurVector<int> vec(2, 4);
    vec.popBack();
    EXPECT_EQ(vec.size(), 1);
}

TEST_F(VectorTest, whenVectorHasSize0ShouldHaveSize0AfterPopBack)
{
    vectorTest.popBack();
    EXPECT_EQ(vectorTest.size(), 0);
}

TEST_F(VectorTest, IteratorBeginPointsToFirstElement) {
    vectorTest.pushBack(10);
    vectorTest.pushBack(11);
    EXPECT_EQ(*(vectorTest.begin()), vectorTest.at(0));
}

TEST_F(VectorTest, IteratorBeginNextPointsToSecondElement) {
    vectorTest.pushBack(10);
    vectorTest.pushBack(11);
    EXPECT_EQ(*(vectorTest.begin() + 1), vectorTest.at(1));
}

TEST_F(VectorTest, IteratorInitializedAndIncrementedPointsToSecondElement) {
    vectorTest.pushBack(10);
    vectorTest.pushBack(11);
    auto i = vectorTest.begin();
    i = i + 1;
    EXPECT_EQ(*i, vectorTest.at(1));
}

TEST_F(VectorTest, IteratorRecognizesWhenIncrementedToEnd) {
    vectorTest.pushBack(10);
    vectorTest.pushBack(11);
    OurVector<int>::RandomAccessIterator i = vectorTest.begin();
    i = i + 2;
    EXPECT_EQ(i, vectorTest.end());
}

TEST_F(VectorTest, UsingAtForChangeSecondElementFromValueAToValueB) {
    int A = 11;
    int B = 22;
    vectorTest.pushBack(10);
    vectorTest.pushBack(A);
    vectorTest.at(1) = B;
    EXPECT_NE(vectorTest.at(1), A);
}

TEST_F(VectorTest, whenCreatedWithInitializerListArratContainsProviedValues) {
    OurVector<int> sut {2, 5, 1, 5, 2, 6};
    EXPECT_EQ(sut.at(3), 5);
}