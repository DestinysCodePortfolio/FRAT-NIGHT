#include "../header/interfaceTerminal.hpp"
#include "../header/scene.hpp"
#include <stdexcept>
#include <iostream>
using std::cout;
using std::endl;
int main() {
	UIScreen* currentScreen = new TitleScreen();
	currentScreen->clearScreen();
	bool running = true;
	while(running){
		currentScreen->printScreen();
		currentScreen->userPrompt();
		try{
			ScreenType nextScreen = currentScreen->screenAction();
			switch (nextScreen) {
				case RUNNING_GAME:
					break;
				case MAIN_GAME:
					delete currentScreen;
					currentScreen = new MainGameScreen();
					break;
				case TITLE:
					delete currentScreen;
					currentScreen = new TitleScreen();
					break;
				case QUIT:
					running = false;
					break;
				default:
					throw std::runtime_error("next Screen wasn't chosen");
			}
		}
		catch(const std::invalid_argument& weirdChoice){
			std::cerr<<weirdChoice.what()<<std::endl;
			running=false;
		}
		catch(const std::runtime_error& wrongNextScreen){
			std::cerr<<wrongNextScreen.what()<<std::endl;
			running=false;
		}
		catch(...){
			std::cerr << "Caught an exception!" << std::endl;
			running=false;
		}
		currentScreen->updateOptions();
	}
	delete currentScreen;
	currentScreen=nullptr;
	return 0;
}