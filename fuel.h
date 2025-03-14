#pragma once
#include <iostream>

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
	};
	//For a starter slope between those - as RPM increases then it goes from a linear to maxDrain
}