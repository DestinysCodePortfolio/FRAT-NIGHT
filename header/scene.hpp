#pragma once
#include <cstdint>
#include <string>
using namespace std;

class Scene{
		char* choice;
		friend class DialogueTree;
	public: 
		Scene()=delete;
		Scene(char& choice);
		~Scene();
		Scene(Scene& other) = delete;
		Scene& operator=(Scene& other);
		virtual void dialogue()=0;   
		void trickleDisplayString(const string& inputString, uint8_t delay); 
};

class openingScene:public Scene{
    void dialogue() override;
};

class takeHug:public Scene{
    void dialogue() override;
};

class rejectHug:public Scene{
    void dialogue() override;
};

