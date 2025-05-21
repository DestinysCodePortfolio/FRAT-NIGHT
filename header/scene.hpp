#pragma once
#include <cstdint>
#include <string>
using namespace std;

class Scene{
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
		~Scene() = default;
		Scene(Scene& other) = delete;
		Scene& operator=(Scene& other);
		virtual void dialogue()=0;   
		void trickleDisplayString(const string& inputString, uint8_t delay); 
};

struct openingScene:public Scene{
    void dialogue() override;
};

struct takeHug:public Scene{
    void dialogue() override;
};

struct rejectHug:public Scene{
    void dialogue() override;
};

