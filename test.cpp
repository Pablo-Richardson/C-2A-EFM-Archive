#include <cmath>
#include <math.h>
#include <iostream>
#include <vector>
#include "atmos.h"
#include "constants.h"
#include "engines.h"
#include "fuel.h"
#include "hydraulics.h"
#include "vec3.h"
#include "liftSurface.h"
#include "damage.h"
using namespace C2A;

int main(int argc, char** argv)
{
	LiftSurface wing;
	std::cout << wing.getDamageLevel() << std::endl;
}





/*
-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------   ARCHIVE   -----------------------------------------------------------------

PRESSURE TEMPERATURE AND DENSITY TEST CODE WORKING 

std::cout << "Altitude: " << atmosphere.getAltitude() << " Meters" << std::endl;
	atmosphere.setPressure(atmosphere.getAltitude());
	std::cout << "Pressure: " << atmosphere.getPressure() << " Pascals" << std::endl;
	atmosphere.setTemperature(atmosphere.getAltitude());
	std::cout << "Temperature: " << atmosphere.getTemperature() << " Kelvin" << std::endl;
	atmosphere.setAirDensity(atmosphere.getPressure(), atmosphere.getTemperature());
	std::cout << "Air Density: " << atmosphere.getAirDensity() << " kg/m^3" << std::endl;
	system("cls");


-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------
*/