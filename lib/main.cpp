#include "../header/interfaceTerminal.hpp"
#include "../header/dialogueTree.hpp"
#include "../header/scene.hpp"
#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;
int main() {
	char userChoice = 0;
	UIScreen* currentScreen = new TitleScreen();
	while(userChoice != 'q' && userChoice != 's' && userChoice!='c'){
		currentScreen->printScreen();
		currentScreen->userPrompt(userChoice);
	}
	delete currentScreen;

	currentScreen->clearScreen();
	if(userChoice == 's'){
		cout<<"User chose s."<<endl;
	}
	else if(userChoice == 'c'){
		cout<<"User chose c."<<endl;
	}
	else if(userChoice == 'q'){
		cout<<"Thanks for playing!!!"<<endl;
		return 0;
	}
	else{
		throw std::invalid_argument("User's choice is a weird option");
	}

	Scene* currentScene = new openingScene;
	currentScene->dialogue();
	delete currentScene;

	return 0;
}