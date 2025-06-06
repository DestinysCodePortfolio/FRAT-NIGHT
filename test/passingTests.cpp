#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

//quickTimeEvent tests
#include "../header/quickTimeEvent.hpp"
#include "../header/DialogueTree.hpp"
#include "../header/interfaceTerminal.hpp"

TEST(DialogueTreeTests, obtainSceneCharacter){
	DialogueTree theTree = DialogueTree();
	EXPECT_EQ(theTree.getCurrentSceneName(), 'o');
}

TEST(UIScreenTests, userPromptTests){
	TitleScreen theScreen= TitleScreen();
	std::stringstream input;
	input << 'o';
	auto original_cin = std::cin.rdbuf(); // Store original cin buffer
	std::cin.rdbuf(input.rdbuf()); // Redirect cin to stringstream
	EXPECT_EQ(theScreen.userPrompt(),'o');
}

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
    input << "\nlrlrlrlrlr";

    auto original_cin = std::cin.rdbuf(); // Store original cin buffer
    std::cin.rdbuf(input.rdbuf()); // Redirect cin to stringstream

    EXPECT_TRUE(runningTest.startEvent());

    std::cin.rdbuf(original_cin);

}

#include "../header/scene.hpp"

TEST(dialogueTests, openingTest){
    openingScene scene1; 
    string correctOutput = string("> You are Natalie Fitzgerald, a university student whose friend went missing at a frat party a couple nights ago.")
    + "\n> You are here at another party, trying to unravel the mystery of her disappearance. You know they did it. You just can't prove it. "
    + "\n My ears throb with every bass drop pounding through the floorboards."
    + "\n  Sweat clings to my back. The house is packed wall to wall—drunken laughter, sticky floors, and that sour-sweet stench of booze and regret."
    + "\n ???: YO! Look who finally decided to pull up!"
    + "\n  A can sprays open. A vodka seltzer fizzes out all over Chad’s hand as he slides into view,  stumbling a little with his arms open."
    + "\n Chad: “Where my hug at?"
    + "\n Take the hug[t]"
    + "\n Reject the hug[r]";
    EXPECT_EQ(scene1.dialogue(), correctOutput); 
}


