#pragma once
#include "../header/scene.hpp"
#include <cstdint>
#include <string>
#include <vector>
using std::string;

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
        ScreenType screenAction() const override; // Changed return type to ScreenType
};

struct MainGameScreen : public UIScreen{
    MainGameScreen();
    ~MainGameScreen() override=default;
    MainGameScreen(MainGameScreen& other) = delete;
    MainGameScreen& operator=(MainGameScreen& other) = delete;
    void printScreen() const override;
    void updateOptions() override;
    ScreenType screenAction() const override; // Changed return type to ScreenType
};