#pragma once
#include <cstdint>
#include <string>
using std::string;

struct UIScreen { //It should be a pure virtual function isnce it is a interface
	UIScreen() = default;
	virtual ~UIScreen()=default;
	UIScreen(UIScreen& other) = delete;
	UIScreen& operator=(UIScreen& other) = delete;
	virtual void printScreen() = 0;
	virtual void userPrompt(char& userChoice);
};

struct TitleScreen : public UIScreen{
	TitleScreen() = default;
	~TitleScreen()=default;
	TitleScreen(TitleScreen& other) = delete;
	TitleScreen& operator=(TitleScreen& other) = delete;
	void printScreen() override;
	void userPrompt(char& userChoice) override;
};

class Scene : public UIScreen {
	uint8_t wordMaxLength;
	string name;
	string description;
	const string FILE_LOCATION;
	
public:
	Scene(): name(""), description(""), wordMaxLength(255), FILE_LOCATION("./lib/FRAT NIGHT SCRIPT.txt") {}
	~Scene() override=default;
	Scene(Scene& otherScene) = delete;
	Scene& operator=(Scene& otherScene) = delete;
	string getName() const;
	string getDescription() const;
	void setName(string newName);
	void setDescription(string newDescription);
	void getSceneFromTextFile(const string& fileName);
	void trickleDisplayString(const string& inputString, uint8_t delay) const;
	void printScreen() override;

};