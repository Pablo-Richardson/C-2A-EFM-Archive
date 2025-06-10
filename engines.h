#pragma once
#include "damage.h"

// Defines engine object as a subclass of object
// Handles engine forces, spooilng, etc.

namespace C2A
{
	class Engine : public Damage
	{
	private:
		int currentRPM;
	public:
		// Constants Needed for the engine
		static constexpr int baseRPM = 0;
		static constexpr int spoolRate = 0; // Rate at which it spools from Idle -> Max Power
		static constexpr int startRate = 0; // Rate at which it spools from 0 -> Idle
		static constexpr int idleRPM = 0;
		static constexpr int maxRPM = 0;
		static constexpr bool engineOn = false; // Whether the engine is on or not

		int getCurrentRPM() { return this->currentRPM; }

		// Constructors - Both default and with passed values.
		Engine(int currentRPM, float damage, float ID, Vec3 position) : Damage(damage, ID, position)
		{
			this->currentRPM = currentRPM;
		}
		Engine() : currentRPM(0), Damage(0, 0, Vec3()) {}
		void updateRPM(float throttlePosition)
		{
			// Update the RPM based on throttle position
			if (throttlePosition < 0.0f) throttlePosition = 0.0f;
			if (throttlePosition > 1.0f) throttlePosition = 1.0f;
			//This currently just sets the RPM based on throttle position, which would lead to instant updates (not realistic)
			//Will adjust in the future to include spool rates
			this->currentRPM = static_cast<int>(idleRPM + (maxRPM - idleRPM) * throttlePosition);
		}
	};
}