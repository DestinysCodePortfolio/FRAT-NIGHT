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
		catch(const std::invalid_argument& weirdChoice){
			std::cerr<<weirdChoice.what()<<std::endl;
		}
		catch(...){
			std::cerr << "Caught an exception!" << std::endl;
		}
		currentScreen->updateOptions();
	}
	delete currentScreen;
	return 0;
}