#include "../header/interfaceTerminal.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <stdexcept>
#include <vector>
using std::cout;
using std::endl;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::flush;
using std::cin;

void TitleScreen::printScreen(){
	
}
void TitleScreen::userPrompt(char& userChoice){
	cout<<"Your choice: ";
	cin>> userChoice;
	cout<<endl;
}

void Scene::printScreen(){
	
	
	
	getSceneFromTextFile(FILE_LOCATION);
	trickleDisplayString(description, 10);
}
void Scene::trickleDisplayString(const string& inputString, uint8_t delay) const{
	for(char currentChar : inputString){
		cout<<currentChar<<flush;
		sleep_for(milliseconds(delay));
	}
	cout<<endl;
}
string Scene::getName() const{
	return name;
}
string Scene::getDescription() const{
	return description;
}
void Scene::setName(string newName){
	name = newName;
}
void Scene::setDescription(string newDescription){
	description = newDescription;
}
void Scene::getSceneFromTextFile(const string& fileName){
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
		description.append(str+'\n');
	}
}