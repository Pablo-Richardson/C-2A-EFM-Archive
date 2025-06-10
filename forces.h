#pragma once
#include "constants.h"
#include "vec3.h"

// Combine forces from each source
// Calculate total force on the aircraft
// From this get acceleration in each direction (over mass)

namespace C2A
{
	Vec3 combineDrag(Vec3 body, Vec3 Lwing, Vec3 Rwing, Vec3 tail, Vec3 rudd, Vec3 flaps, Vec3 gear)
	{
		return(body + Lwing + Rwing + tail + rudd + flaps + gear);
	}

	Vec3 combineLift(Vec3 Lwing, Vec3 Rwing, Vec3 tail, Vec3 flaps)
	{
		return(Lwing + Rwing + tail + flaps);
	}

	Vec3 calculateLift(float Cl, float dens, float speed, float CSA)
	{
		float lift = Cl * dens * speed * speed * 0.5 * CSA;
		Vec3 totalLift(0, lift, 0);
		return totalLift;
	}
}

/*
//Lift - Wing, Aileron, Elevator
	//Gravity - Weight (Fuel, Empty)
	//Get in newtons
	//Sum
	//Handle Moments for rotation - Yikes - Elevator, Aileron
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
*/