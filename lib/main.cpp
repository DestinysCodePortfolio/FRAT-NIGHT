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
		cout<<"printed screen"<<endl;
		currentScreen->userPrompt();
		cout<<"prompted user"<<endl;
		try{
			ScreenType nextScreen = currentScreen->screenAction();
			cout<<"screen action"<<endl;
			switch (nextScreen) {
				case RUNNING_GAME:
					break;
				case MAIN_GAME:
					delete currentScreen;
					currentScreen = new MainGameScreen();
					cout<<"chose main game"<<endl;
					break;
				case TITLE:
					delete currentScreen;
					currentScreen = new TitleScreen();
					cout<<"chose title"<<endl;
					break;
				case QUIT:
					running = false;
					cout<<"chose quit"<<endl;
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
		cout<<"going to update options from main"<<endl;
		currentScreen->updateOptions();
		cout<<"updated options"<<endl;
	}
	delete currentScreen;
	currentScreen=nullptr;
	return 0;
}