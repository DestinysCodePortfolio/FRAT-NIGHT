#pragma once
#include <cstdint>
#include <string>
#include "../header/scene.hpp"
#include <vector>
using std::string;

class UIScreen { //It should be a pure virtual function isnce it is a interface
	protected:
		char userChoice;
	public:
		UIScreen();
		virtual ~UIScreen()=default;
		UIScreen(UIScreen& other) = delete;
		UIScreen& operator=(UIScreen& other) = delete;
		virtual void printScreen() const = 0;
		virtual void updateOptions() = 0;
		virtual bool ifInCurrentChoices() const = 0;
		virtual void screenAction() const = 0;
		void userPrompt();
		void clearScreen() const;
};

class TitleScreen : public UIScreen{
		std::vector<char> currentChoices;
	public:
		TitleScreen();
		~TitleScreen() override=default;
		TitleScreen(TitleScreen& other) = delete;
		TitleScreen& operator=(TitleScreen& other) = delete;
		void printScreen() const override;
		void updateOptions() override;
		void screenAction() const override;
		bool ifInCurrentChoices() const override;
};

struct MainGameScreen : public UIScreen{
	MainGameScreen();
	~MainGameScreen() override=default;
	MainGameScreen(MainGameScreen& other) = delete;
	MainGameScreen& operator=(MainGameScreen& other) = delete;
	void printScreen() const override;
	void updateOptions() override;
	void screenAction() const override;
	bool ifInCurrentChoices() const override;
};