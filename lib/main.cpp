#include "../header/interfaceTerminal.hpp"
#include "../header/scene.hpp"
#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;
int main() {
	char userChoice = 0;
	UIScreen* currentScreen = new TitleScreen();
	while(currentScreen->ifInCurrentChoices(userChoice)){
		currentScreen->printScreen();
		currentScreen->userPrompt(userChoice);
		currentScreen->updateOptions();
		currentScreen->screenAction();
	}
	delete currentScreen;
	return 0;
}