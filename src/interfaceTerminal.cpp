#include "../lib/interfaceTerminal.hpp"
#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;

void UIScreen::printScreen(){
	string currentText = "Hello World :D";
	trickleDisplayString(currentText);
}
void UIScreen::trickleDisplayString(const string& inputString) const{
	for(char currentChar : inputString){
		cout<<currentChar<<std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
	cout<<endl;
}