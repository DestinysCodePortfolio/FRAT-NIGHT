#pragma once
#include <fstream>
class LoadData {
		std::fstream inputData;
	public:
		LoadData() = delete;
		~LoadData()=default;
		LoadData(LoadData& other) = delete;
		LoadData& operator=(LoadData& other) = delete;
		static void loadCurrentScene();
};

class SaveData {
		std::fstream outputData;
	public:
		SaveData() = delete;
		~SaveData()=default;
		SaveData(SaveData& other) = delete;
		SaveData& operator=(SaveData& other) = delete;
		static void saveCurrentScene();
};