#pragma once
#include <cstdint>
#include <string>
#include <vector>
using namespace std;

class Item{
    public:
    const string getItemName();
    bool isInInventory();

    private:
    bool inInventory;
    string name;
};

class Player{
	public:
	void shotMeter();

	private:
	std::vector<Item> inventory;
	uint8_t shotCounter = 0;
};