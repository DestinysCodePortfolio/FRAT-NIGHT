#include "../header/DialogueTree.hpp"
#include <iostream>
DialogueTree::DialogueTree():
	nextPossibleScenes({nullptr,nullptr}),
	currentScene(new openingScene('o'))
{}
DialogueTree::~DialogueTree(){
	if(currentScene)
		delete currentScene;
	for(Scene* currentPossibleScene : nextPossibleScenes){
		if(currentPossibleScene)
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
	}
	nextPossibleScenes.clear();
}

void DialogueTree::printCurrentDialogue()const{
	currentScene->dialogue();
}