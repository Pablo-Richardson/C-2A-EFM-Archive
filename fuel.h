#pragma once
#include "engines.h"

namespace C2A
{
	class Fuel
	{
	private:
		float currentFuelDrain;
		float currentFuel;
	public:
		static constexpr float baseFuelDrain = 0;
		static constexpr float maxFuelDrain = 0;
		float getCurrentFuelDrain () { return currentFuelDrain; }
		float getCurrentFuel      () { return currentFuel     ; }
		void changeFuel(float fuelDrain)
		{
			if (fuelDrain < 0.0f) fuelDrain = 0.0f; // No negative fuel drain
			if (fuelDrain > maxFuelDrain) fuelDrain = maxFuelDrain; // No more than max fuel drain
			currentFuel -= fuelDrain; // Decrease current fuel by the fuel drain amount
		}
	};
	//For a starter slope between those - as RPM increases then it goes from a linear to maxDrain
}