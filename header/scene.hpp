#pragma once
#include <cstdint>
#include <vector>
#include <string>
using std::string;
using std::vector;

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
		virtual string dialogue()=0;
		virtual void updatePossibleScenes(vector<Scene*>& nextPossibleScenes)=0;
};

struct openingScene:public Scene{
	openingScene(): Scene(){}
	openingScene(char name): Scene(name){}
	~openingScene() override=default;
	openingScene(openingScene& other) = delete;
	openingScene& operator=(openingScene& other) = delete;
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct takeHug:public Scene{
	takeHug(): Scene(){}
	takeHug(char name): Scene(name){}
	~takeHug() override=default;
	takeHug(takeHug& other) = delete;
	takeHug& operator=(takeHug& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct rejectHug:public Scene{
	rejectHug(): Scene(){}
	rejectHug(char name): Scene(name){}
	~rejectHug() override=default;
	rejectHug(rejectHug& other) = delete;
	rejectHug& operator=(rejectHug& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};
struct firstShotOptionScene:public Scene{
	firstShotOptionScene(): Scene(){}
	firstShotOptionScene(char name): Scene(name){}
	~firstShotOptionScene() override=default;
	firstShotOptionScene(firstShotOptionScene& other) = delete;
	firstShotOptionScene& operator=(firstShotOptionScene& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};
struct firstShotOptionScene:public Scene{
	firstShotOptionScene(): Scene(){}
	firstShotOptionScene(char name): Scene(name){}
	~firstShotOptionScene() override=default;
	firstShotOptionScene(firstShotOptionScene& other) = delete;
	firstShotOptionScene& operator=(firstShotOptionScene& other) = delete;  
	void dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};
struct takeFirstShot:public Scene{
	takeFirstShot(): Scene(){}
	takeFirstShot(char name): Scene(name){}
	~takeFirstShot() override=default;
	takeFirstShot(takeFirstShot& other) = delete;
	takeFirstShot& operator=(takeFirstShot& other) = delete;  
	void dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct rejectFirstShot:public Scene{
	rejectFirstShot(): Scene(){}
	rejectFirstShot(char name): Scene(name){}
	~rejectFirstShot() override=default;
	rejectFirstShot(rejectFirstShot& other) = delete;
	rejectFirstShot& operator=(rejectFirstShot& other) = delete;  
	void dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct secondShotOptionScene:public Scene{
	secondShotOptionScene(): Scene(){}
	secondShotOptionScene(char name): Scene(name){}
	~secondShotOptionScene() override=default;
	secondShotOptionScene(secondShotOptionScene& other) = delete;
	secondShotOptionScene& operator=(secondShotOptionScene& other) = delete;  
	void dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};


struct takeSecondShot:public Scene{
	takeSecondShot(): Scene(){}
	takeSecondShot(char name): Scene(name){}
	~takeSecondShot() override=default;
	takeSecondShot(takeSecondShot& other) = delete;
	takeSecondShot& operator=(takeSecondShot& other) = delete;  
	void dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct rejectSecondShot:public Scene{
	rejectSecondShot(): Scene(){}
	rejectSecondShot(char name): Scene(name){}
	~rejectSecondShot() override=default;
	rejectSecondShot(rejectSecondShot& other) = delete;
	rejectSecondShot& operator=(rejectSecondShot& other) = delete;  
	void dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};
