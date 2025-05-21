#pragma once
#include <cstdint>


class NPCMeter{
		uint8_t meter;
	public:
		NPCMeter();
		~NPCMeter();
		NPCMeter(NPCMeter& other) = delete;
		NPCMeter& operator=(NPCMeter& other) = delete;
		void increaseMeterByOne();
		void decreaseMeterByOne();
		const uint8_t getCurrentMeter() const;
};