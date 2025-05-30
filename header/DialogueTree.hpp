#pragma once
#include "scene.hpp"
class DialogueTree {
		vector<Scene*> nextPossibleScenes;
		Scene* currentScene;
	public:
		DialogueTree();
		~DialogueTree();
		DialogueTree(DialogueTree& other) = delete;
		DialogueTree& operator=(DialogueTree& other) = delete;
		void updateScene(char userInput);
		void printCurrentDialogue()const;
};