/// color4.h

//INCLUDES
#include"vector4.h"
#include"architecture.h"

#ifndef color4_h
#define color4_h

struct color4 {
	float r;
	float g;
	float b;
	float a;
};

CORE_API void set_color4(struct color4* c, float r, float g, float b, float a);
struct color4 normalized_color4(struct color4 c);
float fbrightness(struct color4 c);
CORE_API vec4 getvector4(struct color4 c);

#endif