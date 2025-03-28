#pragma once
#include "array"
#include "damage.h"
#include "vec3.h"

//Default class for any surface that produces lift, will have calculations for lift and drag
//Calculates lift and drag per lifting surface (maybe drag calculations should be handled in damage no?)

namespace C2A
{
	class LiftSurface : public Damage
	{
	private:
		std::array<float, 21> Cya; //21 indicies from AOA 0 to 20 - For lift coefficient
		std::array<float, 21> Cxa; //Same but for drag coefficient
	public:
		// Constructors - Both emtpy and with passed values
		LiftSurface(std::array<float, 21> Cya, std::array<float, 21> Cxa, float damage, float ID, Vec3 position) : Damage(damage, ID, position)
		{
			this->Cya = Cya;
			this->Cxa = Cxa;
		}
		LiftSurface() : Cya({ 0 }), Cxa({ 0 }), Damage(0, 0, Vec3()) {}
	};
}