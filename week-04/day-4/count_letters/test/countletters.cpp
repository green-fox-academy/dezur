//
// Created by Zoli on 2019. 04. 25..
//

#include "gtest/gtest.h"
#include "countletters.h"

TEST(CountLetterTesting, testWith1Word)
{
    // Arrange
    std::string line = "kiscica";
    char testChar = 'c';
    std::map<char, int> result;

    // Act
    result = countLetters(line);

    // Assert
    ASSERT_EQ(result[testChar], 2);
}

TEST(CountLetterTesting, testWithMultipleWords)
{
    // Arrange
    std::string line = "kiscica kiskutya malacka";
    char testChar = 'a';
    std::map<char, int> result;

    // Act
    result = countLetters(line);

    // Assert
    ASSERT_EQ(result[testChar], 5);
}

TEST(CountLetterTesting, testWithEmptyString)
{
    // Arrange
    std::string line = "";
    char testChar = 'a';
    std::map<char, int> result;

    // Act
    result = countLetters(line);

    // Assert
    ASSERT_EQ(result[testChar], 0);
}