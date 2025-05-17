#include "../header/interfaceTerminal.hpp"
#include "../header/dialogueTree.hpp"
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


	if(userChoice == 's'){
		cout<<"User chose s.\n";
	}
	else if(userChoice == 'c'){
		cout<<"User chose c.\n";
	}
	else if(userChoice == 'q'){
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		cout<<"Thanks for playing!!!"<<endl;
		return 0;
	}
	else{
		throw std::invalid_argument("User's choice is a weird option");
	}

	
	return 0;
}