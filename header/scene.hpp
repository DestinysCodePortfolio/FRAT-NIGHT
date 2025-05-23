#pragma once
#include <vector>
#include <string>
using std::string;
using std::vector;

class Scene{
		char optionName;
		vector<Scene*> nextPossibleScenes;
	protected:
		void trickleDisplayString(const string& inputString, uint8_t delay);
	public: 
		Scene();
		Scene(char name);
		~Scene();
		Scene(Scene& other) = delete;
		Scene& operator=(Scene& other) = delete;
		virtual void dialogue()=0;
		virtual void updatePossibleScenes()=0;
};

struct openingScene:public Scene{
    void dialogue() override;
		void updatePossibleScenes() override;
};

struct takeHug:public Scene{
    void dialogue() override;
		void updatePossibleScenes() override;
};

struct rejectHug:public Scene{
    void dialogue() override;
		void updatePossibleScenes() override;
};

