#include <cmath>
#include <math.h>
#include <iostream>
#include <vector>
#include "atmos.h"
#include "constants.h"
#include "engines.h"
#include "fuel.h"
#include "forces.h"
#include "hydraulics.h"
#include "vec3.h"
#include "liftSurface.h"
#include "damage.h"
using namespace C2A;

//File used to test all my functions and classes


int main(int argc, char** argv)
{
    Vec3 lift = calculateLift(0.5, 1.5, 100, 20);

    std::cout << lift.y;
}







/*
-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------   ARCHIVE   -----------------------------------------------------------------

PRESSURE TEMPERATURE AND DENSITY TEST CODE WORKING 

void testAtmosphere(float altitude)
{
    Atmos atmosphere(altitude);

    std::cout << "Testing Atmosphere at Altitude: " << altitude << " meters" << std::endl;
    std::cout << "Pressure: " << atmosphere.getPressure() << " Pascals" << std::endl;
    std::cout << "Temperature: " << atmosphere.getTemperature() << " Kelvin" << std::endl;
    std::cout << "Air Density: " << atmosphere.getAirDensity() << " kg/m^3" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}



LIFT VEC3 TEST COD WORKING

Vec3 lift(0, 100, 0);
    Vec3 liftCombined = combineLift(lift, lift, lift, lift);
    std::cout << liftCombined.x << " " << liftCombined.y << " " << liftCombined.z << std::endl;


-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------
*/