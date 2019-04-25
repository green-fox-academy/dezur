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