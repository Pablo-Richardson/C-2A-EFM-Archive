#pragma once
#include "constants.h"
#include <iostream>

namespace C2A
{
	class ControlSurface
	{
	private :
		float dragC;
		float liftC;
		float area;
	public:
		float getDragC() { return dragC; }
		float getLiftC() { return liftC; }
		float getArea () { return area ; }
	};
	class Elevator : ControlSurface
	{

	};
	class Aileron : ControlSurface
	{

	};
	class Rudder : ControlSurface
	{

	};
}