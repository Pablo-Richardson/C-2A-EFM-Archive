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
	public:
		static constexpr double mol = 0.02896;
		static constexpr double gasConst = 287.05;
		static constexpr double gasConstPress = 8.3143;

		Atmos(float alt)
		{
			setAltitude(alt);
			setPressure(alt);
			setTemperature(alt);
			setAirDensity(pressure, temperature);
		}
		Atmos()
		{
			//Just for safety -> Not going to actually create objects using this
			altitude = 0.0f;
			airDensity = 0.0f;
			pressure = 0.0f;
			temperature = 0.0f;
		}

		float getTemperature () { return temperature; }
		float getPressure    () { return pressure   ; }
		float getAirDensity  () { return airDensity ; }
		float getAltitude    () { return altitude   ; }

		void setAltitude(float alt) { altitude = alt; }

		void setAtmosphere(float temp, float press, float airDens, float alt)
		{
			temperature = temp;
			pressure = press;
			airDensity = airDens;
			altitude = alt;
		}

		void setPressure(float alt)
		{
			float bracket = 1 + ((-0.0065 / 288) * (alt - 0));
			float power = (-1 * C2A::grav * mol) / (gasConstPress * -0.0065);
			pressure = (101325 * pow(bracket, power));
		}

		void setTemperature(float alt)
		{
			float altFeet = alt * 3.281;
			float temp = 59 - (0.00356 * altFeet);
			temp = (temp - 32) * 5 / 9;
			this->temperature = (temp + 273.15);
		}

		void setAirDensity(float pressure, float temp)
		{
			float airDensity = pressure / (gasConst * temp);
			this->airDensity = airDensity;
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