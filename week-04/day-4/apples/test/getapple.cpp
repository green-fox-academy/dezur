//
// Created by Zoli on 2019. 04. 25..
//


#include "gtest/gtest.h"
#include "getapple.h"

TEST(appleTesting, returnIsApple)
{
    // Arrange
    std::string returnstring;

    // Act
    std::string result = getApple();

    // Assert
    ASSERT_EQ(result, "apple");

}

TEST(appleTesting, returnIsNotApple)
{
    // Arrange
    std::string returnstring;

    // Act
    std::string result = getApple();

    // Assert
    ASSERT_NE(result, "apple");

}