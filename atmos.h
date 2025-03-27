#pragma once
#include "constants.h"
#include <cmath>

namespace C2A
{
	class Atmos
	{
	private:
		float temperature;
		float pressure;
		float airDensity;
		float altitude;

		static constexpr double mol = 0.02896;
		static constexpr double gasConst = 287.05;
		static constexpr double gasConstPress = 8.3143;
		static constexpr float tempLapseRate = -0.0065;
		static constexpr float seaLevelTemp = 288.15; 
		static constexpr float seaLevelPressure = 101325;
		static constexpr float feetToMeters = 0.3048;
		static constexpr float fahrenheitToCelsius = 5.0 / 9.0;
		static constexpr float celsiusToKelvin = 273.15;

	public:
		// Constructor to instantiate the atmosphere at a given altitude
		Atmos(float alt)
		{
			setAltitude(alt);
			setPressure(alt);
			setTemperature(alt);
			setAirDensity(pressure, temperature);
		}
		Atmos() = default;

		// Getters for atmospheric properties
		inline float getTemperature() const { return temperature; }
		inline float getPressure() const { return pressure; }
		inline float getAirDensity() const { return airDensity; }
		inline float getAltitude() const { return altitude; }

		// Setter for altitude
		inline void setAltitude(float alt) { altitude = alt; }

		// Setter for all atmospheric properties
		inline void setAtmosphere(float temp, float press, float airDens, float alt)
		{
			temperature = temp;
			pressure = press;
			airDensity = airDens;
			altitude = alt;
		}

		// Estimate and set pressure based on altitude using the barometric formula
		inline void setPressure(float alt)
		{
			float bracket = 1 + (tempLapseRate / seaLevelTemp) * alt;
			float power = (-C2A::grav * mol) / (gasConstPress * tempLapseRate);
			pressure = seaLevelPressure * std::pow(bracket, power);
		}

		// Estimate and set temperature based on altitude
		inline void setTemperature(float alt)
		{
			float altFeet = alt / feetToMeters;
			float tempF = 59 - (0.00356 * altFeet);
			float tempC = (tempF - 32) * fahrenheitToCelsius;
			temperature = tempC + celsiusToKelvin;
		}

		// Estimate and set air density based on pressure and temperature
		inline void setAirDensity(float pressure, float temp)
		{
			airDensity = pressure / (gasConst * temp);
		}
	};
}




/*
-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------   ARCHIVE   -----------------------------------------------------------------
float temperature = 0.0f;
float pressure = 0.0f;
float airDensity = 0.0f;


double const mol = 0.02896;
		double const gasConst = 287.05;
		double const gasConstPress = 8.3143;
		float pressure(float& alt)
		{
			float bracket = 1 + ((-0.0065 / 288) * (alt - 0));
			float power = (-1 * grav * mol) / (gasConstPress * -0.0065);
			this->pressure = (101325 * pow(bracket, power));
		}
		void airDens(float& pressure, float& temp)
		{
			//Air Density = Air Pressure / (Specific Gas Constant * Temperature)
			float airDensity = pressure / (gasConst * temp);

			this->airDensity = airDensity;
		}
		void temperature(float& alt)
		{
			//If statement to account for pause of temperature change between 10k and 20k meters high
			if (alt > 10000)
			{
				this->temperature = (-49.8909 + 273.15);
			}
			float altFeet = alt * 3.281;
			float temp = 59 - (0.00356 * altFeet);
			temp = (temp - 32) * 5 / 9;
			this->temperature = (temp + 273.15);
		}
-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------
*/