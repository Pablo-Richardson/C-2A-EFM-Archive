#pragma once

namespace C2A
{
	 static constexpr float grav = 9.807;
	 float Cx0; // Declare this later - Drag coefficient at 0 AOA
	 float Cy0; // Declare this later - Lift coefficient at 0 AOA
	 float Cya[]; //Array of lift coefficients per AOA - Anything greater than X is a stall (so only needs to go up to like 15 indicies)
	 float Cx0[]; //Array of drag doefficients per AOA
	 float Cymax; //Declare later - stall AOA
	 float kjx; //Roll rate constant acceleration
}