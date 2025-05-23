#include "../header/DialogueTree.hpp"
DialogueTree::DialogueTree():
	currentScene(nullptr)
{}
DialogueTree::~DialogueTree(){
	delete currentScene;
}