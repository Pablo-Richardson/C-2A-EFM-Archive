#pragma once
#include <iostream>

namespace C2A
{
	class Engine
	{
	private:
		int currentRPM; 
		int damageLevel = 0;
	public:
		static constexpr int baseRMP = 0;
		static constexpr float spoolTime = 0; //Time from Idle-100%
		static constexpr float startTime = 0; //Time from 0-Idle
		static constexpr int idleRPM = 0;
		static constexpr int maxRPM = 0;

		int   getCurrentRPM  () { return currentRPM ; }
		int   getDamageLevel () { return damageLevel; }
	};
}