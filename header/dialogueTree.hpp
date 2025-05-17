#pragma once
#include <string>
using std::string;
class DialogueTree {
		struct Dialogue {
			string info;
			Dialogue* option1;
			Dialogue* option2;
			Dialogue* option3;
			Dialogue* option4;
			Dialogue():
				info(""),
				option1(nullptr),
				option2(nullptr),
				option3(nullptr),
				option4(nullptr)
			{}
			~Dialogue(){
				delete option1;
				delete option2;
				delete option3;
				delete option4;
			}
			Dialogue(Dialogue& other) = delete;
			Dialogue& operator=(Dialogue& other) = delete;
		};
	public:
		DialogueTree() = default;
		~DialogueTree()=default;
		DialogueTree(DialogueTree& other) = delete;
		DialogueTree& operator=(DialogueTree& other) = delete;
		string startAt(Dialogue& );
		string getLine();
		string getOptions();
};