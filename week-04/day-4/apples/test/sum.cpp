//
// Created by Zoli on 2019. 04. 25..
//

#include "gtest/gtest.h"
#include "sum.h"

TEST(sumTesting, testSumOfVectorElements)
{
    // Arrange
    std::vector<int> listOfIntegers = {1, 2, 3, 4, 5, 6, 7};

    // Act
    int result = sum(listOfIntegers);

    // Assert
    ASSERT_EQ(result, 28);
}

TEST(sumTesting, testSumOfVectorElementsIfListIsEmpty)
{
    // Arrange
    std::vector<int> listOfIntegers ;

    // Act
    int result = sum(listOfIntegers);

    // Assert
    ASSERT_EQ(result, 0);
}

TEST(sumTesting, testSumOfVectorElementsWith1Element)
{
    // Arrange
    std::vector<int> listOfIntegers = {1};

    // Act
    int result = sum(listOfIntegers);

    // Assert
    ASSERT_EQ(result, 1);
}

TEST(sumTesting, testSumOfVectorElementsWithMultipleElements)
{
    // Arrange
    std::vector<int> listOfIntegers = {1,2,3,4};

    // Act
    int result = sum(listOfIntegers);

    // Assert
    ASSERT_EQ(result, 10);
}

TEST(sumTesting, testSumOfVectorElementsWithNegativeSum)
{
    // Arrange
    std::vector<int> listOfIntegers = {-1,-2,-3,-4};

    // Act
    int result = sum(listOfIntegers);

    // Assert
    ASSERT_EQ(result, -10);
}