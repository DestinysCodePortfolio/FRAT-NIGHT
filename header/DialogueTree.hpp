#pragma once
#include "scene.hpp"
class DialogueTree {
		Scene* currentScene;
	public:
		DialogueTree();
		~DialogueTree();
		DialogueTree(DialogueTree& other) = delete;
		DialogueTree& operator=(DialogueTree& other) = delete;
		void updateScene();
		void printCurrentDialogue();
};