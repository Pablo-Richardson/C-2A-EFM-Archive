#pragma once
#include "constants.h"
#include "vec3.h"

namespace C2A
{
	//Lift - Wing, Aileron, Elevator
	//Drag - Body, Gear, Flaps
	//Gravity - Weight (Fuel, Empty)
	//Get in newtons
	//Sum
	//Handle Moments for rotation - Yikes - Elevator, Aileron
	//Take lift as a center force 
	//Moment depends on trim and speed
	//So we do the aelerons sepeartely
	//Track Rotation
	//Calculate lift in direction of rotation
	//Split into component vectors
	//Same with drag -> Backwards of direction of velocity always
	//velocity should be a vector
	//Find magnitude to get speed
	//Acceleration as vector
	// Force/Mass
	//Maybe per object? This could be better as it would allow for more specific functions all with the same name...
	Vec3 calculateLift(float Cya, float airDens, float speed, float wingSurface) 
	{
		
	}
	Vec3 calculateWingDrag(float Xya, float airDens, float speed)
	{

	}
	Vec3 calculateAileronMoment()
	{

	}
}