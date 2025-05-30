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
//Copy constructor
// Scene& Scene::operator=(const Scene& other) {
//     if (this != &other) {
//         this->choice = other.choice;
//     }
//     return *this;
// }


//openers dialogue-- until where my hug at
Scene::Scene():
	optionName(0)
{}
Scene::Scene(char name):
	optionName(name)
{}
char Scene::getOptionName(){
	return optionName;
}
void openingScene::dialogue(){
    string output = "You are Natalie Fitzgerald, a university student whose friend went missing at a frat party...\n";
    trickleDisplayString(output, 1);

    // cin >> userChoice;

    // if (choice == 'a') {
    //     return new takeHug();
    // } else if (choice == 'b') {
    //     return new rejectHug();
    // }

    // return nullptr; // if invalid input
}
void openingScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeHug('t');
	nextPossibleScenes.at(1)=new rejectHug('r');
	std::cout<<"Updated possible Scenes\n";
}


//if you take the hug
void takeHug::dialogue(){
    string output = "";
    output = " He reeks of tequila and cologne that never fully covered up whatever he did last night.\n Natalie: Chad, have you been drinking?! \n Chad: Have you not? It's Halloweekend, babe. \n It’s Thursday.";
    trickleDisplayString(output, 50);
}
void takeHug::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	for(Scene* currentPointer : nextPossibleScenes){
		cout<<currentPointer->getOptionName()<<endl;
	}
}

//if you dont take the hug
void rejectHug::dialogue(){
    string output = "";
    output = "Damn, Natalie. Acting brand new?";
    trickleDisplayString(output, 50);
}
void rejectHug::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	for(Scene* currentPointer : nextPossibleScenes){
		cout<<currentPointer->getOptionName()<<endl;
	}
}

//Continuing scene: kevin and lilith intro
void firstShotOptionScene::dialogue(){
    string output = "";
    output = "Natalie: Whatever. Have you seen [REDACTED]? She was not at her apartment, has not shown up to class, and her location is off… 
    \n Chad: Bro… I dunno. She is probably out getting hazed with her bigs or whatever. \n His eyes light up. 
    \nChad: But yo, forget that—you need to catch up. SHOTS. NOW. \n He grabs my arm, dragging me towards the kitchen. 
    \n Lilith: That girl was so hard to keep still — \n Kevin: NATALIEEE! Youre so late! Lilith already threw up twice! 
    \n It is 10:15 pm…the party started at 10. \n Lilith: Kevin, that was you. \n Kevin: IT IS FIVE O'CLOCK SOMEWHEREEEE, SO— 
    \n Lilith: So where is that friend of yours? [REDACTED], right? \n Natalie: I could ask you the same question. Aren't you the sweetheart of this frat? 
    \n Lilith: I mean, yeah—but we got like, over a hundred girls rushing. I dont remember every newbie.
    \n Chad walks pulls two bottles out of the fridge, waving them around.
    \n Chad : PICK YOUR POISON!
    \n Take the shot[t]
    \n Reject the shot[r]";
    trickleDisplayString(output, 50);
}
void firstShotOptionScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeFirstShot('t');
	nextPossibleScenes.at(1)=new rejectFirstShot('r');
	std::cout<<"Updated possible Scenes\n";
}

//take first shot
void secondShotOptionScene::dialogue(){
    string output = "";
    output = "Kevin: WOOOAAAAAHH THAS LIQA!!!
    \n Lilith: I'm tired of babysitting him, Chad, tag in.
    \n Lilith grabs my arm and pulls me to the couch.
    \n Lilith: So what do you think of Kevin , he's cute huh? 
    \n Well yes..
    \n Natalie: Dude…
    \n Lilith: My bad I'm just trying to help my bro out. After all, I heard that you and your man just broke up..
    \n She pulls out small bottle of tequila from her purse.
    \n Lilith: Oops did that slip out , well I'm too deep in now to not tell you, but i need another shot so WE forget that I told you!
    \n Take the shot: Kevin’s cute, and I wanna know more[t]
    \n Reject the shot: I need to find my friend[r]";
    trickleDisplayString(output, 50);
}
void secondShotOptionScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeSecondShot('t');
	nextPossibleScenes.at(1)=new rejectSecondShot('r');
	std::cout<<"Updated possible Scenes\n";
}


//reject first shot 
void rejectFirstShot::dialogue(){
    string output = "";
    output = "Chad: I know you're paranoid about your friend and all , but she aint here little lady. Stop killing the vibe.
    \n Natalie - Fine I'll find her myself, jerk.";
    trickleDisplayString(output, 50);
}


//takes second shot


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
