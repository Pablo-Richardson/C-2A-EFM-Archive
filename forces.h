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

	float getCya(float AOA)
	{
		//This is a placeholder until the actual calculations can be made
		return 0.0f;
	}
	float getCxa(float AOA)
	{
		//This is a placeholder until the actual calculations can be made
		return 0.0f;
	}
	Vec3 calculateLift(float Cya, float airDens, float speed, float wingSurface) 
	{
		float lift = 0.5 * Cya * airDens * pow(speed, 2) * wingSurface;
		return Vec3(0, lift, 0);
	}
	Vec3 calculateWingDrag(float Xya, float airDens, float speed)
	{
		float drag = 0.5 * Xya * airDens * pow(speed, 2);
		return Vec3(-drag, 0, 0);
	}
	//Placeholders until these calculations can be made (need center of mass infomration)
	Vec3 calculateAileronMoment()
	{
		float momentX = 0.0f;
		float momentY = 0.0f;
		float momentZ = 0.0f;
		return Vec3(momentX, momentY, momentZ);
	}
	Vec3 calculateElevatorMoment()
	{
		float momentX = 0.0f;
		float momentY = 0.0f;
		float momentZ = 0.0f;
		return Vec3(momentX, momentY, momentZ);
	}
}