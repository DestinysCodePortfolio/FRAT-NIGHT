#include "../header/DialogueTree.hpp"
#include <iostream>
DialogueTree::DialogueTree():
	currentScene(new openingScene('o'))
{}
DialogueTree::~DialogueTree(){
	if (currentScene!=nullptr){
		delete currentScene;
		currentScene=nullptr;
	}
	for(Scene* currentPointer : nextPossibleScenes){
		if(currentPointer!=nullptr){
			delete currentPointer;
			currentPointer=nullptr;
		}
	}
	nextPossibleScenes.clear();
}
void DialogueTree::updateScene(char userInput){
	std::cout<<"going to update possible scenes size: "<<nextPossibleScenes.size()<<std::endl;
	currentScene->updatePossibleScenes(nextPossibleScenes);
	std::cout<<"did to update possible scenes with user option: "<<userInput<<std::endl;
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