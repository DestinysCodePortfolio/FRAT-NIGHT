#include "../header/interfaceTerminal.hpp"
#include <stdexcept>
#include <iostream>
using std::cout;
int main() {
	char userChoice = 0;
	TitleScreen currentScreen;
	while(userChoice != 'q' && userChoice != 's' && userChoice!='c'){
		currentScreen.printScreen();
		currentScreen.userPrompt(userChoice);
	}

	if(userChoice == 's'){
		cout<<"User chose s.\n";
	}
	else if(userChoice == 'c'){
		cout<<"User chose c.\n";
	}
	else if(userChoice == 'q'){
		cout<<"User chose q.\n";
	}
	else{
		throw std::invalid_argument("User's choice is a weird option");
	}
	return 0;
}