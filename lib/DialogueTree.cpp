#include "../header/DialogueTree.hpp"
DialogueTree::DialogueTree():
	currentScene(nullptr)
{}
DialogueTree::~DialogueTree(){
	if (currentScene!=nullptr){
		delete currentScene;
	}
}
void DialogueTree::updateScene(char userInput){
	for(Scene* currentPossibleScene : nextPossibleScenes){
		if(userInput==currentPossibleScene->getOptionName()){
			delete currentScene;
			currentScene=currentPossibleScene;
		}
	}
}

void DialogueTree::printCurrentDialogue()const{
	currentScene->dialogue();
}