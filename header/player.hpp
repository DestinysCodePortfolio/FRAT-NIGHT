#pragma once
#include <cstdint>
#include <string>
#include <vector>
using namespace std;

class Item{
		bool inInventory;
		string name;
	public:
		Item();
		~Item();
		Item(Item& other) = delete;
		Item& operator=(Item& other) = delete;
		const string getItemName();
		bool isInInventory();
};

class Player{
		vector<Item> inventory;
		uint8_t shotCounter;
	public:
		Player();
		~Player();
		Player(Player& other) = delete;
		Player& operator=(Player& other) = delete;
		void increaseShotCoutnerByOne();
};