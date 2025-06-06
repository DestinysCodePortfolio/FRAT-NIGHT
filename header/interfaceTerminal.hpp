#pragma once
#include "scene.hpp"
#include "DialogueTree.hpp"
#include <cstdint>
#include <string>
#include <vector>
using std::string;

enum ScreenType {
	TITLE,
	MAIN_GAME,
	QUIT,
	RUNNING_GAME
};

class UIScreen { //It should be a pure virtual function since it is an interface
    protected:
        char userChoice;
    public:
        UIScreen();
        virtual ~UIScreen()=default;
        UIScreen(UIScreen& other) = delete;
        UIScreen& operator=(UIScreen& other) = delete;
        virtual void printScreen() const = 0;
        virtual void updateOptions() = 0;
        virtual ScreenType screenAction() const = 0; // Changed return type to ScreenType
        // void userPrompt();
				char userPrompt();
        void clearScreen() const;
};

struct TitleScreen : public UIScreen{
	TitleScreen();
	~TitleScreen() override=default;
	TitleScreen(TitleScreen& other) = delete;
	TitleScreen& operator=(TitleScreen& other) = delete;
	void printScreen() const override;
	void updateOptions() override;
	ScreenType screenAction() const override; // Changed return type to ScreenType
};

class MainGameScreen : public UIScreen{
    DialogueTree* theTree;
	public:
		MainGameScreen();
    ~MainGameScreen();
    MainGameScreen(MainGameScreen& other) = delete;
    MainGameScreen& operator=(MainGameScreen& other) = delete;
    void printScreen() const override;
    void updateOptions() override;
    ScreenType screenAction() const override; // Changed return type to ScreenType
};