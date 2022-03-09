#include "gtest/gtest.h"
#include "OurVector.hpp"
#include <stdexcept>


struct VectorTest :public ::testing::Test
{
    OurVector<int> vectorTest;
};


// Iterator Tests
// ________________________________________________________________
TEST(VectorIteratorTest, checkForEachLoopOnOurVector)
{
    OurVector<int> v{ 1, 2, 3 };
    int index{ 0 };
    for (auto i : v)
    {
        EXPECT_EQ(i, v[index]);
        ++index;
    }
}


TEST(VectorIteratorTest, whenEndCalledReturnIteratorToOnePastLastElement)
{
    OurVector<int> v{ 1, 2, 3 };
    auto iter1{ v.end() };

    EXPECT_EQ(*(--iter1), v.at(2));
}

TEST(VectorIteratorTest, whenVectorIteratorsAreNotEqualReturnFalse)
{
    OurVector<int> v{ 1, 2, 3 };
    auto iter1{ v.begin() };
    auto iter2{ ++(v.begin()) };

    EXPECT_FALSE(iter1 == iter2);
    EXPECT_TRUE(iter1 != iter2);

}

TEST(VectorIteratorTest, whenVectorIteratorsAreEqualReturnTrue)
{
    OurVector<int> v{ 1, 2, 3 };
    auto iter1{ v.begin() };
    auto iter2{ v.begin() };

    EXPECT_TRUE(iter1 == iter2);
    EXPECT_FALSE(iter1 != iter2);
}

TEST(VectorIteratorTest, when1SubtractedFromIteratorReturn4)
{
    OurVector<int> v{ 4, 7 };
    auto iter = v.begin();
    ++iter;
    EXPECT_EQ(*(iter - 1), v.at(0));
}

TEST(VectorIteratorTest, when2AddedToIteratorReturn5)
{
    OurVector<int> v{ 2, 8, 5 };
    auto iter = v.begin();
    EXPECT_EQ(*(iter + 2), v.at(2));
}

TEST(VectorIteratorTest, when1AddedToIteratorReturn8)
{
    OurVector<int> v{ 2, 8 };
    auto iter = v.begin();
    EXPECT_EQ(*(iter + 1), v.at(1));
}

TEST(VectorIteratorTest, whenMemebersAccessedWithIteratorReturnMemberValues)
{
    struct Pair
    {
        int x{ 3 };
        int y{ 6 };
    };

    Pair a{};
    OurVector<Pair> v{ a };
    auto iter = v.begin();

    EXPECT_EQ(iter->x, 3);
    EXPECT_EQ(iter->y, 6);

}

TEST(VectorIteratorTest, whenIteratorPostDecrementedShouldPointAtFirstElement)
{
    OurVector<int> v{ 8, 2, 5 };
    auto iter = v.begin();
    iter++;
    iter--;
    EXPECT_EQ(*(iter), v.at(0));
}

TEST(VectorIteratorTest, whenIteratorPostDecrementedTemporaryObjectShouldPointAtSecondElement)
{
    OurVector<int> v{ 8, 2, 5 };
    auto iter = v.begin();
    ++iter;
    EXPECT_EQ(*(iter--), v.at(1));
}

TEST(VectorIteratorTest, whenIteratorPreDecrementedShouldPointAtFirstElement)
{
    OurVector<int> v{ 8, 2, 5 };
    auto iter = v.begin();
    ++iter;
    EXPECT_EQ(*(--iter), v.at(0));
}

TEST(VectorIteratorTest, whenIteratorPostIncrementedShouldPointAtSecondElement)
{
    OurVector<int> v{ 8, 2, 5 };
    auto iter = v.begin();
    iter++;
    EXPECT_EQ(*(iter), v.at(1));
}

TEST(VectorIteratorTest, whenIteratorPostIncrementedTemporaryObjectShouldPointAtFirstElement)
{
    OurVector<int> v{ 8, 2, 5 };
    auto iter = v.begin();
    EXPECT_EQ(*(iter++), v.at(0));
}

TEST(VectorIteratorTest, whenIteratorPreIncrementedShouldPointAtSecondElement)
{
    OurVector<int> v{ 8, 2, 5 };
    auto iter = v.begin();
    EXPECT_EQ(*(++iter), v.at(1));
}

TEST(VectorIteratorTest, whenBeginCalledReturnIteratorToFirstElement)
{
    OurVector<int> v{ 8, 2, 5 };
    EXPECT_EQ(*(v.begin()), v.at(0));
}

// Iterator Tests end
// _____________________________________

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
    EXPECT_THROW(vectorTest.at(6), std::out_of_range);
}

TEST_F(VectorTest, whenUsingNegativeIndexShouldThrowExcept)
{
    EXPECT_THROW(vectorTest.at(-1), std::out_of_range);
}

TEST_F(VectorTest, whenChangedVectorValueWithAtMethodTo5ItIs5)
{
    OurVector<int> vec(1);
    int expectedValue{ 5 };
    vec.at(0) = 5;
    EXPECT_EQ(vec.at(0), expectedValue);
}

TEST_F(VectorTest, vectorCanStoreDifferentDataTypes)
{
    std::string testValue{ "testCase" };
    OurVector<std::string> sut(1, testValue);
    EXPECT_EQ(sut.at(0), testValue);
}

TEST_F(VectorTest, whenCapacityIsOverCopyElementsToNewArray)
{
    vectorTest.pushBack(2);
    EXPECT_EQ(vectorTest.size(), 1);
    EXPECT_EQ(vectorTest.capacity(), 1);
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

// TEST_F(VectorTest, IteratorBeginPointsToFirstElement) {
//     vectorTest.pushBack(10);
//     vectorTest.pushBack(11);
//     EXPECT_EQ(*(vectorTest.begin()), vectorTest.at(0));
// }

// TEST_F(VectorTest, IteratorBeginNextPointsToSecondElement) {
//     vectorTest.pushBack(10);
//     vectorTest.pushBack(11);
//     EXPECT_EQ(*(vectorTest.begin() + 1), vectorTest.at(1));
// }

// TEST_F(VectorTest, IteratorInitializedAndIncrementedPointsToSecondElement) {
//     vectorTest.pushBack(10);
//     vectorTest.pushBack(11);
//     auto i = vectorTest.begin();
//     i = i + 1;
//     EXPECT_EQ(*i, vectorTest.at(1));
// }

// TEST_F(VectorTest, IteratorRecognizesWhenIncrementedToEnd) {
//     vectorTest.pushBack(10);
//     vectorTest.pushBack(11);
//     OurVector<int>::RandomAccessIterator i = vectorTest.begin();
//     i = i + 2;
//     EXPECT_EQ(i, vectorTest.end());
// }

TEST_F(VectorTest, whenCreatedWithInitializerListShouldContainProviedValues) {
    OurVector<int> sut{ 2, 5, 1, 5, 2, 6 };
    EXPECT_EQ(sut.at(3), 5);
}

TEST_F(VectorTest, whenEmplacingElementShouldStoreItInContainer) {
    OurVector<std::pair<int, int>> sut;
    std::pair<int, int> testPair{ 1, 5 };
    sut.emplaceBack(1, 5);
    EXPECT_EQ(sut.at(0).first, testPair.first);
    EXPECT_EQ(sut.at(0).second, testPair.second);
}

TEST_F(VectorTest, whenUsingSquareBracketsOperatorShouldReturnSameValueRoundBracketsDo) {
    OurVector<int> sut{ 1, 2, 3 };
    EXPECT_EQ(sut[0], sut.at(0));
    EXPECT_EQ(sut[1], sut.at(1));
    EXPECT_EQ(sut[2], sut.at(2));
}

TEST_F(VectorTest, whenChangingValuewithSquareBracketsTo5ItIs5) {
    OurVector<int> sut(1, 0);
    int testValue{ 5 };
    sut[0] = testValue;
    EXPECT_EQ(sut[0], testValue);
}

TEST_F(VectorTest, whenVectorIsClearedItsSizeIs0) {
    OurVector<int> sut(5, 0);
    sut.clear();
    EXPECT_EQ(sut.size(), 0);
}

TEST_F(VectorTest, whenVectorIsResized) {
    OurVector<int> sut(5, 0);
    sut.clear();
    EXPECT_EQ(sut.size(), 0);
}

TEST_F(VectorTest, whenVectorIsShrunkToSizeItsCapacityEqualsSize) {
    OurVector<int> sut(5, 0);
    sut.pushBack(1);
    sut.shrinkToSize();
    EXPECT_EQ(sut.size(), sut.capacity());
}