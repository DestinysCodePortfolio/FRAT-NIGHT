#pragma once
#include <cstdint>
#include <string>
#include "../header/scene.hpp"
#include <vector>
using std::string;

class UIScreen { //It should be a pure virtual function isnce it is a interface
	protected:
		std::vector<char> currentChoices;
		char userChoice;
	public:
		UIScreen();
		virtual ~UIScreen()=default;
		UIScreen(UIScreen& other) = delete;
		UIScreen& operator=(UIScreen& other) = delete;
		virtual void printScreen() const = 0;
		void userPrompt();
		virtual void updateOptions() = 0;
		bool ifInCurrentChoices() const;
		virtual void screenAction() const = 0;
		void clearScreen() const;
};

struct TitleScreen : public UIScreen{
	TitleScreen();
	~TitleScreen()=default;
	TitleScreen(TitleScreen& other) = delete;
	TitleScreen& operator=(TitleScreen& other) = delete;
	void printScreen() const override;
	void updateOptions() override;
	void screenAction() const override;
};

struct MainGameScreen : public UIScreen{
	MainGameScreen();
	~MainGameScreen()=default;
	MainGameScreen(MainGameScreen& other) = delete;
	MainGameScreen& operator=(MainGameScreen& other) = delete;
	void printScreen() const override;
	void updateOptions() override;
	void screenAction() const override;
};