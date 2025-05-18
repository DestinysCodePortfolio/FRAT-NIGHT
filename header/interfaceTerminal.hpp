#pragma once
#include <cstdint>
#include <string>
#include "../header/scene.hpp"
#include <vector>
using std::string;

struct UIScreen { //It should be a pure virtual function isnce it is a interface
	protected:
		std::vector<char> currentChoices;
		char userChoice;
	public:
		UIScreen();
		virtual ~UIScreen()=default;
		UIScreen(UIScreen& other) = delete;
		UIScreen& operator=(UIScreen& other) = delete;
		virtual void printScreen() = 0;
		virtual void userPrompt() =0;
		virtual void updateOptions() = 0;
		virtual bool ifInCurrentChoices() = 0;
		virtual void screenAction() = 0;
		void clearScreen();
};

class TitleScreen : public UIScreen{
		const uint8_t BOX_WIDTH; // length of the box
	public:
		TitleScreen();
		~TitleScreen()=default;
		TitleScreen(TitleScreen& other) = delete;
		TitleScreen& operator=(TitleScreen& other) = delete;
		bool ifInCurrentChoices() override;
		void printScreen() override;
		void userPrompt() override;
		void updateOptions() override;
		void screenAction() override;
};

struct MainGameScreen : public UIScreen{
	MainGameScreen()=default;
	~MainGameScreen()=default;
	MainGameScreen(MainGameScreen& other) = delete;
	MainGameScreen& operator=(MainGameScreen& other) = delete;
	void printScreen() override;
	void userPrompt() override;
};