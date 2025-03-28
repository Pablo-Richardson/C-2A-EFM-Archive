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

		int getCurrentRPM() { return this->currentRPM; }

		// Constructors - Both default and with passed values.
		Engine(int currentRPM, float damage, float ID, Vec3 position) : Damage(damage, ID, position)
		{
			this->currentRPM = currentRPM;
		}
		Engine() : currentRPM(0), Damage(0, 0, Vec3()) {}
	};
}