#pragma once
#include "array"
#include "vec3.h"
#include "damage.h"
namespace C2A
{
	class LiftSurface : public Damage 
	{
	private:
		std::array<float, 14> Cya;
		std::array<float, 14> Cxa;
	public:
		LiftSurface(std::array<float, 14> Cya, std::array<float, 14> Cxa, float damage, float ID, Vec3 position) : Damage(damage, ID, position)
		{
			this->Cya = Cya;
			this->Cxa = Cxa;
		}
		LiftSurface() : Cya({ 0 }), Cxa({ 0 }), Damage(0, 0, Vec3()) {}
	};
}

/*
private:
		float damageLevel;
		float ID;
		Vec3 position;
	public:
		Damage(float damage, float ID, Vec3 position)
		{
			this->damageLevel = damage;
			this->ID = ID;
			this->position = position;
		}
		Damage() = default;
		float getDamageLevel() const { return damageLevel; }
		float getID() const { return ID; }
		Vec3 getPosition() const { return position; }
		float setDamageLevel(float damage) { damageLevel += damage; }
*/