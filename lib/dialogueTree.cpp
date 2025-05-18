#include "../header/dialogueTree.hpp"

void MainGameScreen::printScreen(){
	Scene* currentScene = new openingScene;
	currentScene->dialogue();
	delete currentScene;
}

void MainGameScreen::userPrompt(char& userChoice){
	
}
void MainGameScreen::DialogueTree::userPrompt(char& userChoice){
	
}