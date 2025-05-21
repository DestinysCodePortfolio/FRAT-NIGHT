#pragma once

#include <chrono>
#include <string>
 //only included for testing not useful after prolly

class quickTimeEvent {
		double duration; 
		std::string userInp;
		std::string soln;
	public:
		quickTimeEvent(double dur, std::string crrctAns);
		void setDuration(double newDur);
		double getDuration();
		bool startEvent();
};

