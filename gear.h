#pragma once
#include "hydraulics.h"

namespace C2A
{
	class Gear
	{
	private:
		int currentPos = 0; //0 = inside, 1 = extending, 2 = out fully (adjust drag based on this)
		int damageLevel;
	public:
		static constexpr float timeToExtend = 0.0f;
		static constexpr float cx_gear = 0.0f;

		float getCurrentPos() { return currentPos; }
		void setCurrentPos(float& position) { currentPos = position; }

		void extendGear(float &hyrualicPress)
		{
			if (currentPos != 0)
			{
				return;
			}
		}
	};



	class Flaps
	{
	private:
		float currentAngle = 0.0f;

	public:
		static constexpr float timeToExtend = 0.0f;
		static constexpr float maxAngle = 0.0f;
		static constexpr float Cya = 0.0f;

		float getCurrentAngle() { return currentAngle; }
		void setCurrentAngle(float &angle) { currentAngle = angle; }
	};
}