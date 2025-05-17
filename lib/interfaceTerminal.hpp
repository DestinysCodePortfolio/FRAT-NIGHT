#pragma once
#include <cstdint>
#include <string>
using std::string;
class UIScreen {
		const uint8_t CHAR_MAX_LENGTH;
		uint8_t delay;
	public:
		UIScreen(): CHAR_MAX_LENGTH(255), delay(0){}
		UIScreen(uint8_t charAmount, uint8_t desiredDelay): CHAR_MAX_LENGTH(charAmount), delay(desiredDelay){}
		~UIScreen()=default;
		UIScreen(UIScreen& otherUIScreen) = delete;
		UIScreen& operator=(UIScreen& otherUIScreen) = delete;
		void printScreen();
		void trickleDisplayString(const string& inputString) const;
};