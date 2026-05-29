/// motionfs.c

// INCLUDES
#include"motionfs.h"
#include<math.h>

float expdecay(float a1, float a2, float r, float x)
{
	return a2 + (a1 - a2) * pow(e, -x * r);
}
float expamplifier(float a1, float a2, float r, float x)
{
	return a2 - (a2 - a1) * pow(e, -x * r);
}
float exp_lerp_routine(float a1, float a2, float r, float x)
{
	if (a1 > a2) {
		return expdecay(a1, a2, r, x);
	}
	else if (a1 < a2) {
		return expamplifier(a1, a2, r, x);
	}
	else {
		return a1;
	}
}
