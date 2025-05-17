#include "../header/player.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::flush;
using std::cin;


//increments shot counter
void Player::shotMeter(){
    shotCounter++;
}

//item name accessor
const string Item::getItemName(){
    return name;
}

//inventory status accessor
bool Item::isInInventory(){
    return inInventory;
}

