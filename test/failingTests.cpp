#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

//quickTimeEvent tests
#include "../header/quickTimeEvent.hpp"


TEST(quickTimeTestsFail, getDurTestFail){
    quickTimeEvent checkDuration(5, "test");
    EXPECT_NE(checkDuration.getDuration(), 50);
}

TEST(quickTimeTestsFail, setDurTestFail){
    quickTimeEvent checkSetDuration(5, "test");
    checkSetDuration.setDuration(20);
    EXPECT_NE(checkSetDuration.getDuration(), 200);
}


TEST(quickTimeTestsFail, runningTestFail){
    quickTimeEvent runningTest(10, "lrlrlrlrlr");

    std::stringstream input;
    input << "rlrlrlrlrl";

    auto original_cin = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf()); 

    EXPECT_FALSE(runningTest.startEvent());

    std::cin.rdbuf(original_cin);

}


#include "../header/scene.hpp"

TEST(dialogueTestsF, openingTestF){
    openingScene scene1; 
    string incorrectOutput = string(":(");
    EXPECT_NE(scene1.dialogue(), incorrectOutput); 
}

TEST(dialogueTestsF, hugTestF){
    takeHug scene2;
    string incorrectOutput = string(":(");
    EXPECT_NE(scene2.dialogue(), incorrectOutput);
}

TEST(dialogueTestsF, noHugTestF){
    rejectHug scene2;
    string incorrectOutput = string(":(");
    EXPECT_NE(scene2.dialogue(), incorrectOutput);
}

#include "../header/DialogueTree.hpp"
TEST(dialogueTreeF, nextSceneTest){
    DialogueTree* exTree = new DialogueTree();
    char testSceneName = exTree->getCurrentSceneName();
    EXPECT_NE(testSceneName, '0');
}
