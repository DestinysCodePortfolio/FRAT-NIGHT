#pragma once
#include <cstdint>
#include <string>
using namespace std;

class Scene{
		char* choice;
		struct DialogueTree{
			struct choices {
				choices() = default;
				~choices()=default;
				choices(choices& other) = delete;
				choices& operator=(choices& other) = delete;
			};
			DialogueTree() = default;
			~DialogueTree()=default;
			DialogueTree(DialogueTree& other) = delete;
			DialogueTree& operator=(DialogueTree& other) = delete;
		};
	public: 
		Scene() = default;
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

