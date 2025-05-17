#pragma once
#include <cstdint>
#include <string>
using std::string;

class NonPlayableCharacter : public UIScreen {
	uint8_t trustMeter;
	// characterDialogues: DialogueTree;
public:
 virtual ~NonPlayableCharacter() = default;
};

class chad : public NonPlayableCharacter {
	uint8_t agressionMeter;
public:
};

class lilith : public NonPlayableCharacter {
	uint8_t intoxicatedMeter;
public:
};

class kevin : public NonPlayableCharacter {
	uint8_t romanceMeter;
public:
};
