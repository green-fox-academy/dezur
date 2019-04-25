//
// Created by Zoli on 2019. 04. 25..
//

#include "gtest/gtest.h"
#include "checkanagram.h"

TEST(AnagramTesting, testWithAnAnagramWord)
{
    // Arrange
    std::string word1 = "dog";
    std::string word2 = "god";

    // Act
    bool result = checkAnagram(word1, word2);

    // Assert
    ASSERT_EQ(result, true);

}

TEST(AnagramTesting, testWithNonAnagramWord)
{
    // Arrange
    std::string word1 = "dog";
    std::string word2 = "git";

    // Act
    bool result = checkAnagram(word1, word2);

    // Assert
    ASSERT_EQ(result, false);

}