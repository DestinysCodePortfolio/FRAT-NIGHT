#include "../header/DialogueTree.hpp"
#include <iostream>
DialogueTree::DialogueTree():
	nextPossibleScenes({nullptr,nullptr}),
	currentScene(new openingScene('o'))
{}
DialogueTree::~DialogueTree(){
	delete currentScene;
	for(Scene* currentPossibleScene : nextPossibleScenes){
			delete currentPossibleScene;
	}
	nextPossibleScenes.clear();
}
void DialogueTree::updateScene(char userInput){
	currentScene->updatePossibleScenes(nextPossibleScenes);
	for(Scene* currentPossibleScene : nextPossibleScenes){
		if(userInput==currentPossibleScene->getOptionName()){
			delete currentScene;
			currentScene=currentPossibleScene;
		}
		else{
			delete currentPossibleScene;
		}
		currentPossibleScene=nullptr;
	}
}

void DialogueTree::printCurrentDialogue()const{
	currentScene->dialogue();
}