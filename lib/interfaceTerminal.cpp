#include "../header/interfaceTerminal.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;

UIScreen::UIScreen():
	userChoice(0)
{}

void UIScreen::userPrompt(){
	cout<<"Your choice: ";
	cin>> userChoice;
	cout<<endl;
}

void UIScreen::clearScreen() const{
	// Clear screen (cross-platform)
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
TitleScreen::TitleScreen():
	UIScreen(){
	currentChoices = {0};
}
void TitleScreen::printScreen() const {
	const string GAME_TITLE = "FRAT NIGHT!";
	const string MENU_OPTIONS[] = {
		"1. Start Game [s]",
		"2. Continue Game [c]",
		"3. Quit [q]"
	};
	const int NUM_OPTIONS = 3;
	const uint8_t BOX_WIDTH = 40; // changes length of title screen box

	// Double-line border characters
	const char CORNER = '+';
	const char HORIZONTAL = '=';
	const char VERTICAL = '|';

	// Helper lambda to center text
	auto centerText = [&BOX_WIDTH](const string &text) {
		int padding = (BOX_WIDTH - text.length()) / 2;
		if (padding < 0) padding = 0;
		return string(padding, ' ') + text;
	};

	// Top border
	cout << CORNER << string(BOX_WIDTH, HORIZONTAL) << CORNER << endl;

	// Game title (centered)
	cout << VERTICAL << centerText(GAME_TITLE) 
					<< std::setw(BOX_WIDTH - centerText(GAME_TITLE).length() + 1) << VERTICAL << endl;

	// Divider line
	cout << VERTICAL << string(BOX_WIDTH, HORIZONTAL) << VERTICAL << endl;

	// Menu options (centered)
	for (int i = 0; i < NUM_OPTIONS; ++i) {
		cout << VERTICAL << centerText(MENU_OPTIONS[i]) << std::setw(BOX_WIDTH - centerText(MENU_OPTIONS[i]).length() + 1) << VERTICAL << endl;
	}

	// Bottom border
	cout << CORNER << string(BOX_WIDTH, HORIZONTAL) << CORNER << endl;
}
void TitleScreen::updateOptions(){}
ScreenType TitleScreen::screenAction() const{
	clearScreen();
	if(userChoice == 's'){
		cout<<"Starting game."<<endl;
		return MAIN_GAME;
	}
	else if(userChoice == 'c'){
		cout<<"Loading game."<<endl;
		 return MAIN_GAME;
	}
	else if(userChoice == 'q'){
		cout<<"Thanks for playing!!!"<<endl;
		return QUIT;
	}
	else{
		throw std::invalid_argument("Try again!");
	}
}
MainGameScreen::MainGameScreen():
	UIScreen(),
	theTree()
{}
void MainGameScreen::printScreen() const {
	cout<<"main game print screen"<<endl;
}
void MainGameScreen::updateOptions(){
	std::cout<<"going to update options"<<endl;
	theTree->updateScene(userChoice);
	std::cout<<"did to update options"<<endl;
}
ScreenType MainGameScreen::screenAction() const{
	clearScreen();
	if(userChoice == 's'){
		cout<<"Starting game."<<endl;
	}
	else if(userChoice == 'c'){
		cout<<"Loading game."<<endl;
	}
	else if(userChoice == 'q'){
		cout<<"Thanks for playing!!!"<<endl;
	}
	else{
		throw std::invalid_argument("Try again!");
	}
	return QUIT;
}