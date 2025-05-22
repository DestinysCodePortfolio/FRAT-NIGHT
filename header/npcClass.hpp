#pragma once
#include <cstdint>
#include <string>
using std::string;

class NonPlayableCharacter  {
	uint8_t trustMeter;
	// characterDialogues: DialogueTree;
public:
 virtual ~NonPlayableCharacter() = default;
 void gainTrust ();
 void looseTrust();
};
class chad : public NonPlayableCharacter {
	uint8_t agressionMeter;
	public:
	 void agression();
	

};

class lilith : public NonPlayableCharacter {
	uint8_t intoxicatedMeter;
	public:
	 void intoxicated();
};

class kevin : public NonPlayableCharacter {
	uint8_t romanceMeter;
	public:
	 void romance();
};
