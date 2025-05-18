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
void openingScene::dialogue(){
    string output = "You are Natalie Fitzgerald, a university student whose friend went missing at a frat party...\n";
    trickleDisplayString(output, 1);

    cin >> choice*;

    // if (choice == 'a') {
    //     return new takeHug();
    // } else if (choice == 'b') {
    //     return new rejectHug();
    // }

    // return nullptr; // if invalid input
}

Scene::Scene(char& userChoice): 
	choice(userChoice)
{}
Scene::~Scene(){
	choice=nullptr;
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

void Scene:: trickleDisplayString(const string& inputString, uint8_t delay){
	for(char currentChar : inputString){
		cout<<currentChar<<flush;
		sleep_for(milliseconds(delay));
	}
	cout<<endl;
}