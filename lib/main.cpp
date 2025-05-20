#include "../header/interfaceTerminal.hpp"
#include "../header/scene.hpp"
#include <stdexcept>
#include <iostream>

int main() {
	UIScreen* currentScreen = new TitleScreen();
	currentScreen->clearScreen();
	while(currentScreen->ifInCurrentChoices()){
		currentScreen->printScreen();
		currentScreen->userPrompt();
		try{
			currentScreen->screenAction();
		}
		catch(std::invalid_argument weirdChoice){
			std::cout<<weirdChoice.what()<<std::endl;
		}
		currentScreen->updateOptions();
	}
	delete currentScreen;
	return 0;
}