/// color4.c

// INCLUDES
#include"color4.h"
#include<math.h>

void set_color4(struct color4* c, float r, float g, float b, float a)
{
	c->r = r;
	c->g = g;
	c->b = b;
	c->a = a;
}

struct color4 normalized_color4(struct color4 c) {
	float r = c.r / 255;
	float g = c.g / 255;
	float b = c.b / 255;
	float a = c.a / 255;
	struct color4 normal;
	set_color4(&normal, r, g, b, a);
	return normal;
}

float fbrightness(struct color4 c) {
	return (c.r + c.g + c.b) / 3;
}

vec4 getvector4(struct color4 c) {
	vec4 v;
	set(&v, c.r, c.g, c.b, c.a);
	return v;
}