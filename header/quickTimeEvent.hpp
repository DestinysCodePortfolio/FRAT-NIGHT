#pragma once

#include <chrono>
#include <string>
 //only included for testing not useful after prolly

class quickTimeEvent {
		double duration; 
		std::string userInp;
		std::string soln;
	public:
		quickTimeEvent()=delete;
		quickTimeEvent(double dur, std::string crrctAns);
		~quickTimeEvent() = default;
		quickTimeEvent(quickTimeEvent& other) = delete;
		quickTimeEvent& operator=(quickTimeEvent& other) = delete;
		void setDuration(double newDur);
		double getDuration();
		bool startEvent();
};

