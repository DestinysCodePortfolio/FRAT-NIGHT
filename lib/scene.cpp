#include "../header/scene.hpp"
#include "../header/interfaceTerminal.hpp"
#include <iostream>
#include <thread>
#include <sstream>
#include <vector>
using namespace std;
using std::string;
using std::cout;
using std::endl;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::flush;
using std::cin;


//openers dialogue-- until where my hug at
void openingScene::dialogue(){
    string output = "";
    output = "You are Natalie Fitzgerald, a university student whose friend went missing at a frat party a couple nights ago. \n \n Sweat clings to my back. The house is packed wall to wall—drunken laughter, sticky floors, and \n that sour-sweet stench of booze and regret. \n \n ???: YO! Look who finally decided to pull up! \n \n A can sprays open. A vodka seltzer fizzes out all over Chad’s hand as he slides into view, \n stumbling a little with his arms open. \n \n Chad: Where my hug at? \n \n 1. Take The Hug [a] \n 2. Reject The Hug [b]";
    trickleDisplayString(output, 50);
    //string choice;
    //cin >> choice;
    //if(choice == "a") takeHug();
    //else if(choice == "b") rejectHug();

}

//if you take the hug
void takeHug::dialogue(){
    string output = "";
    output = " He reeks of tequila and cologne that never fully covered up whatever he did last night.";
    trickleDisplayString(output, 50);
}

//if you dont take the hug
void rejectHug::dialogue(){
    string output = "";
    output = "Damn, Natalie. Acting brand new?";
    trickleDisplayString(output, 50);
}

void Scene::trickleDisplayString(const string& inputString, uint8_t delay){
    const size_t BOX_WIDTH = 70; // Width inside the borders
    const size_t PADDING = 2;
    const size_t MAX_LINE = BOX_WIDTH - PADDING * 2;

    std::istringstream inputStream(inputString);
    std::vector<string> lines;
    string rawLine;

    // Word-wrap logic
    while (std::getline(inputStream, rawLine)) {
        std::istringstream wordStream(rawLine);
        string word, line;
        while (wordStream >> word) {
            if (line.length() + word.length() + 1 > MAX_LINE) {
                lines.push_back(line);
                line = word;
            } else {
                if (!line.empty()) line += " ";
                line += word;
            }
        }
        if (!line.empty()) {
            lines.push_back(line);
        }
        if (rawLine.empty()) lines.push_back("");
    }

    // Box characters
    const char CORNER = '+';
    const char HORIZONTAL = '=';
    const char VERTICAL = '|';

    // Top border
    cout << CORNER << string(BOX_WIDTH, HORIZONTAL) << CORNER << endl;

    // Display lines with borders and padding
    for (const auto& l : lines) {
        string padded = string(PADDING, ' ') + l;
        padded += string(BOX_WIDTH - padded.length(), ' '); // Right space padding
        cout << VERTICAL;
        for (char c : padded) {
            cout << c << flush;
            sleep_for(milliseconds(delay));
        }
        cout << VERTICAL << endl;
    }

    // Bottom border
    cout << CORNER << string(BOX_WIDTH, HORIZONTAL) << CORNER << endl;
}
