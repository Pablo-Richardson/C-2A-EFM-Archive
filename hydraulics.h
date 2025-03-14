#pragma once

namespace C2A
{
	class Hydraulics
	{
	private:
		//Find out how many hydraulic systems it has (main, probably a back up one too not sure)
		float hydraulicPress;
	public:
		static constexpr float basePress = 0;

		float getHydraulicPress() { return hydraulicPress; }
		void setHydrualicPress(float &pressure) { hydraulicPress = pressure; }
		Hydraulics() { hydraulicPress = 0; }
	};
}