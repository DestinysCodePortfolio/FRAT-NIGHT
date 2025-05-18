#pragma once
#include <string>
using std::string;
struct MainGameScreen : UIScreen{
	struct DialogueTree{
		friend class scene;
		DialogueTree() = default;
		~DialogueTree()=default;
		DialogueTree(DialogueTree& other) = delete;
		DialogueTree& operator=(DialogueTree& other) = delete;
	};
	void printScreen() override;
	void userPrompt(char& userChoice) override;
};

