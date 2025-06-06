#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

//quickTimeEvent tests
#include "../header/quickTimeEvent.hpp"
#include "../lib/interfaceTerminal.cpp"

TEST(quickTimeTests, getDurTest){
    quickTimeEvent checkDuration(5, "test");
    EXPECT_EQ(checkDuration.getDuration(), 5);
}

TEST(quickTimeTests, setDurTest){
    quickTimeEvent checkSetDuration(5, "test");
    checkSetDuration.setDuration(20);
    EXPECT_EQ(checkSetDuration.getDuration(), 20);
}


TEST(quickTimeTests, runningTest){
    quickTimeEvent runningTest(10, "lrlrlrlrlr");

    std::stringstream input;
    input << "lrlrlrlrlr";

    auto original_cin = std::cin.rdbuf(); // Store original cin buffer
    std::cin.rdbuf(input.rdbuf()); // Redirect cin to stringstream

    EXPECT_TRUE(runningTest.startEvent());

    std::cin.rdbuf(original_cin);

}
TEST(DialogueTreeTests, UpdateOptionsTests){
	DialogueTree theTree();
	
}