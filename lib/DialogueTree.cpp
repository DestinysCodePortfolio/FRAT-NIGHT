#include "../header/DialogueTree.hpp"
DialogueTree::DialogueTree():
	currentScene(nullptr)
{}
DialogueTree::~DialogueTree(){
	if (currentScene!=nullptr){
		delete currentScene;
	}
}