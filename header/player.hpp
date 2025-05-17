#pragma once
#include <cstdint>
#include <string>
using std::string;


class Player{
    public:
    const void shotMeter();

    private:
    vector<item> inventory;
    int shotCounter = 0;
};

class Item{
    public:
    const string getItemName();
    bool isInInventory();

    private:
    bool inInventory;
    string name;
};