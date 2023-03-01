#include "gtest/gtest.h"
#include "gallows.h"
#include <iostream>
#include <fstream>

// Test for test1 function
TEST(Test1, CorrectInput) {
    EXPECT_TRUE(test1(1));
    EXPECT_TRUE(test1(2));
}

TEST(Test1, IncorrectInput) {
    EXPECT_FALSE(test1(-1));
    EXPECT_FALSE(test1(0));
    EXPECT_FALSE(test1(3));
}

// Test for test2 function
TEST(Test2, CorrectInput) {
    std::ifstream dict("dictionary.txt");
    EXPECT_TRUE(test2(dict));
}

TEST(Test2, IncorrectInput) {
    std::ifstream dict("incorrect_file.txt");
    EXPECT_FALSE(test2(dict));
}

// Test GamePlay function
TEST(GamePlayTest, CorrectInputTest) {
    char star[] = {'*', '*', '*', '*', '*', '\0'};
    char word[] = {'T', 'E', 'S', 'T', '\0'};
    int letter = 4;

    // Simulate user input
    std::stringstream input("T\n");

    // Redirect cin to the stringstream
    std::streambuf* origCin = std::cin.rdbuf(input.rdbuf());

    // Call the function and check return value and output
    EXPECT_TRUE(GamePlay(star, word, letter));
    EXPECT_STREQ(star, "T****");

    // Restore cin
    std::cin.rdbuf(origCin);
}


TEST(GamePlayTest, IncorrectInputTest) {
    char star[] = {'*', '*', '*', '*', '*', '\0'};
    char word[] = {'T', 'E', 'S', 'T', '\0'};
    int letter = 4;

    // Simulate user input
    std::stringstream input("A\n");

    // Redirect cin to the stringstream
    std::streambuf* origCin = std::cin.rdbuf(input.rdbuf());

    // Call the function and check return value and output
    EXPECT_FALSE(GamePlay(star, word, letter));
    EXPECT_STREQ(star, "*****");

    // Restore cin
    std::cin.rdbuf(origCin);
}

// Test PartyGame function
TEST(PartyGameTest, IncorrectInputTest) {
    // Simulate user input
    std::stringstream input("TEST\nA\nB\nC\nD\nE\nF\nG\nH\n");

    // Redirect cin to the stringstream
    std::streambuf* origCin = std::cin.rdbuf(input.rdbuf());

    // Call the function and check output
    testing::internal::CaptureStdout();
    PartyGame();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("You are lose") != std::string::npos);

    // Restore cin
    std::cin.rdbuf(origCin);
}

// Test SoloGame function
TEST(SoloGameTest, CorrectInputTest) {
    // Simulate user input
    std::stringstream input("2\nT\nE\nS\nT\n");

    // Redirect cin to the stringstream
    std::streambuf* origCin = std::cin.rdbuf(input.rdbuf());

    // Call the function and check output
    testing::internal::CaptureStdout();
    SoloGame();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.find("You are win!!!!!") != std::string::npos);

    // Restore cin
    std::cin.rdbuf(origCin);
}

// Tests for SoloGame
TEST(SoloGameTest, ReturnsTrueOnValidInput) {
    std::stringstream input("1\nA\n");
    std::streambuf* old_cin = std::cin.rdbuf(input.rdbuf());
    testing::internal::CaptureStdout();
    SoloGame();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("A word for guessing:"), 0);
    std::cin.rdbuf(old_cin);
}

TEST(SoloGameTest, ReturnsFalseOnInvalidInput) {
    std::stringstream input("2\n");
    std::streambuf* old_cin = std::cin.rdbuf(input.rdbuf());
    testing::internal::CaptureStdout();
    SoloGame();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.find("Not corrective number"), 0);
    std::cin.rdbuf(old_cin);
}
