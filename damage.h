#pragma once
#include "vec3.h"

namespace C2A
{
	class Damage
	{
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
		Damage() : damageLevel(0), ID(0), position(Vec3()) {} 
		float getDamageLevel() const { return damageLevel; }
		float getID() const { return ID; }
		Vec3 getPosition() const { return position; }
		void setDamageLevel(float damage) { damageLevel += damage; }
	};
}
