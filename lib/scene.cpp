#include "../header/scene.hpp"
#include "../header/interfaceTerminal.hpp"
#include <iostream>
#include <thread>
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
    output = " He reeks of tequila and cologne that never fully covered up whatever he did last night.";
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

void Scene:: trickleDisplayString(const string& inputString, uint8_t delay){
	for(char currentChar : inputString){
		cout<<currentChar<<flush;
		sleep_for(milliseconds(delay));
	}
	cout<<endl;
}