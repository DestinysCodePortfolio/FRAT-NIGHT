#include "../header/interfaceTerminal.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;

void UIScreen::clearScreen(){
	// Clear screen (cross-platform)
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void TitleScreen::printScreen(){
	clearScreen();
	const int BOX_WIDTH = 40;  // Adjust width as needed
	const string GAME_TITLE = "FRAT NIGHT!";
	const string MENU_OPTIONS[] = {
		"1. Start Game [s]",
		"2. Continue Game [c]",
		"3. Quit [q]"
	};
	const int NUM_OPTIONS = 3;

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
void TitleScreen::userPrompt(char& userChoice){
	cout<<"Your choice: ";
	cin>> userChoice;
	cout<<endl;
}

/* ------> If we want to use this to get stuff from files
void UIScreen::getSceneFromTextFile(const string& fileName){
	std::ifstream file(fileName);
	if(!file.is_open()){
		throw std::runtime_error("File didn't open correctly");
	}
	string line;
	std::vector<string> lines;
	int i = 0;
	while (std::getline(file, line)) {
			lines.push_back(line);
			if (i == 5){
				break;
			}
	}
	file.close();
	for (string& str : lines) {
		cout << str << endl;
	}
}
*/