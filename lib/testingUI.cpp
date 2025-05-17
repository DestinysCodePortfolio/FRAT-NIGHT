#include <iostream>
#include <string>
#include <iomanip>  // For std::setw
using std::string;
using std::cout;
using std::cin;
using std::endl;;
struct GameUI {
	static void titleScreen() {
			// Clear screen (cross-platform)
			#ifdef _WIN32
					system("cls");
			#else
					system("clear");
			#endif

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
			cout << CORNER << string(BOX_WIDTH, HORIZONTAL) << CORNER << endl;;

			// Game title (centered)
			cout << VERTICAL << centerText(GAME_TITLE) 
								<< std::setw(BOX_WIDTH - centerText(GAME_TITLE).length() + 1) << VERTICAL << endl;;

			// Divider line
			cout << VERTICAL << string(BOX_WIDTH, HORIZONTAL) << VERTICAL << endl;;

			// Menu options (centered)
			for (int i = 0; i < NUM_OPTIONS; ++i) {
					cout << VERTICAL << centerText(MENU_OPTIONS[i]) 
										<< std::setw(BOX_WIDTH - centerText(MENU_OPTIONS[i]).length() + 1) << VERTICAL << endl;;
			}

			// Bottom border
			cout << CORNER << string(BOX_WIDTH, HORIZONTAL) << CORNER << endl;;
	}
	static void userPrompt(char& userChoice){
		cout<<"Your choice: ";
		cin>> userChoice;
		cout<<endl;
	}
};

int main() {
	char userChoice = 0;
	while(userChoice != 'q'){
		GameUI::titleScreen();
		GameUI::userPrompt(userChoice);
	}
	return 0;
}