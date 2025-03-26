#pragma once
#include "constants.h"
#include "vec3.h"
#include "array"

namespace C2A
{
	class liftingSurface
	{
		float damage;
		float ID;
		float area;
		float Cy0;
		float Cx0;
		std::array<float, 15> Cya;
		std::array<float, 15> Cxa;

		liftingSurface(float damage, float ID, float area, float Cy0, float Cx0, std::array<float, 15> Cya, std::array<float, 15> Cxa)
		{
			this->damage = damage;
			this->ID = ID;
			this->area = area;
			this->Cy0 = Cy0;
			this->Cx0 = Cx0;
			this->Cya = Cya;
			this->Cxa = Cxa;
		}

		liftingSurface() = default;

		float getDamage() const { return damage; }
		float getID() const { return ID; }
		float getArea() const { return area; }
		float getCy0() const { return Cy0; }
		float getCx0() const { return Cx0; }
		float getCya(float AOA) const
		{
			if (AOA > 30)
			{
				return 0.0f;
			}
			else 
			{
				//Get AOA to become a number between 0-14 (So find out its ratio in that respect)
				//Then find the two closest values in the array and interpolate between them
				float ratio = AOA / 30;
				int index = ratio * 14;
				float lower = Cya[index];
				float upper = Cya[index + 1];
				float difference = upper - lower;
				float interpolated = lower + (difference * ratio);
				return interpolated;
			}
		}
		float getCxa(float AOA) const
		{
			if (AOA > 30)
			{
				return 0.0f;
			}
			else
			{
				//Get AOA to become a number between 0-14 (So find out its ratio in that respect)
				//Then find the two closest values in the array and interpolate between them
				float ratio = AOA / 30;
				int index = ratio * 14;
				float lower = Cxa[index];
				float upper = Cxa[index + 1];
				float difference = upper - lower;
				float interpolated = lower + (difference * ratio);
				return interpolated;
			}
		}

	};
}

/*
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


*/