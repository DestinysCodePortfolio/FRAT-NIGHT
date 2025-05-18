#pragma once
#include <cstdint>
#include <string>
using std::string;

class UIScreen { //It should be a pure virtual function isnce it is a interface
		uint8_t wordMaxLength;
	public:
		UIScreen(): 
			wordMaxLength(255)
		{}
		virtual ~UIScreen()=default;
		UIScreen(UIScreen& other) = delete;
		UIScreen& operator=(UIScreen& other) = delete;
		virtual void printScreen() = 0;
		virtual void userPrompt(char& userChoice) =0;
		void clearScreen();
		// void getSceneFromTextFile(const string& fileName);
};

struct TitleScreen : public UIScreen{
	TitleScreen() = default;
	~TitleScreen()=default;
	TitleScreen(TitleScreen& other) = delete;
	TitleScreen& operator=(TitleScreen& other) = delete;
	void printScreen() override;
	void userPrompt(char& userChoice) override;

};