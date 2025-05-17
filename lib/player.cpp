#include "../header/player.hpp"
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


//increments shot counter
const void shotMeter(){
    shotCounter++;
}

//item name accessor
const string getItemName(){
    return name;
}

//inventory status accessor
bool isInInventory(){
    return inInventory;
}

