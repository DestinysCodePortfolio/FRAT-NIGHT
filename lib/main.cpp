#include "../header/interfaceTerminal.hpp"
#include "../header/scene.hpp"
#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;
int main() {
	static char userChoice = 0;
	UIScreen* currentScreen = new TitleScreen();
	currentScreen->clearScreen();
	while(currentScreen->ifInCurrentChoices()){
		currentScreen->printScreen();
		// cout<<"test1"<<endl;
		currentScreen->userPrompt();
		// cout<<"test2"<<endl;
		try{
			currentScreen->screenAction();
		}
		catch(std::invalid_argument weirdChoice){
			cout<<weirdChoice.what()<<endl;
		}
		// cout<<"test3"<<endl;
		currentScreen->updateOptions();
		// cout<<"test4"<<endl;
	}
	// cout<<"Exiting program"<<endl;
	// cout<<"test5"<<endl;
	delete currentScreen;
	return 0;
}