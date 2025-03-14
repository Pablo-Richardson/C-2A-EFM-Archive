#pragma once
#include <iostream>
#include "constants.h"
using namespace C2A;

namespace C2A
{
	namespace AERO
	{
		//function to grab lift coefficient based on AOA
		float getLiftC(float& aoa);

		//function to calcualte lift created by each surface - should call it individually for each lifting surface
		float calcLift(float &CL, float &airDens, float &vel, int &surfaceArea);
	}
}