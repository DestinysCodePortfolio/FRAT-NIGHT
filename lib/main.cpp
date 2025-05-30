#include "../header/interfaceTerminal.hpp"
#include "../header/scene.hpp"
#include <stdexcept>
#include <iostream>
int main() {
    UIScreen* currentScreen = new TitleScreen();
    currentScreen->clearScreen();
    bool running = true;
while(running){
    currentScreen->printScreen();
    currentScreen->userPrompt();
    try{
        ScreenType next = currentScreen->screenAction();
        if (next == MAIN_GAME) {
            delete currentScreen;
            currentScreen = new MainGameScreen();
        } else if (next == TITLE) {
            delete currentScreen;
            currentScreen = new TitleScreen();
        } else if (next == QUIT) {
            running = false;
        }
    }
    catch(const std::invalid_argument& weirdChoice){
        std::cerr<<weirdChoice.what()<<std::endl;
    }
    catch(...){
        std::cerr << "Caught an exception!" << std::endl;
    }
    currentScreen->updateOptions();
}
    delete currentScreen;
    return 0;
}