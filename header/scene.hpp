#pragma once
#include <cstdint>
#include <vector>
#include <string>
using std::string;
using std::vector;
enum ScreenType {
    TITLE,
    MAIN_GAME,
    QUIT
};

class Scene{
		const char optionName;
	protected:
		void trickleDisplayString(const string& inputString, uint8_t delay);
	public: 
		Scene();
		Scene(char name);
		virtual ~Scene() = default;
		Scene(Scene& other) = delete;
		Scene& operator=(Scene& other) = delete;
		char getOptionName();
		virtual void dialogue()=0;
		virtual void updatePossibleScenes(vector<Scene*>& nextPossibleScenes)=0;
};

struct openingScene:public Scene{
	openingScene(): Scene(){}
	openingScene(char name): Scene(name){}
	~openingScene() override=default;
	openingScene(openingScene& other) = delete;
	openingScene& operator=(openingScene& other) = delete;
	void dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct takeHug:public Scene{
	takeHug(): Scene(){}
	takeHug(char name): Scene(name){}
	~takeHug() override=default;
	takeHug(takeHug& other) = delete;
	takeHug& operator=(takeHug& other) = delete;  
	void dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct rejectHug:public Scene{
	rejectHug(): Scene(){}
	rejectHug(char name): Scene(name){}
	~rejectHug() override=default;
	rejectHug(rejectHug& other) = delete;
	rejectHug& operator=(rejectHug& other) = delete;  
	void dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

