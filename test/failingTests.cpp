#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

//quickTimeEvent tests
#include "../header/quickTimeEvent.hpp"


TEST(quickTimeTestsFail, getDurTestFail){
    quickTimeEvent checkDuration(5, "test");
    EXPECT_NE(checkDuration.getDuration(), 5);
}

TEST(quickTimeTestsFail, setDurTestFail){
    quickTimeEvent checkSetDuration(5, "test");
    checkSetDuration.setDuration(20);
    EXPECT_NE(checkSetDuration.getDuration(), 20);
}


TEST(quickTimeTestsFail, runningTestFail){
    quickTimeEvent runningTest(10, "lrlrlrlrlr");

    std::stringstream input;
    input << "rlrlrlrlrl";

    auto original_cin = std::cin.rdbuf(); // Store original cin buffer
    std::cin.rdbuf(input.rdbuf()); // Redirect cin to stringstream

    EXPECT_FALSE(runningTest.startEvent());

    std::cin.rdbuf(original_cin);

}
