// vector4.c

// INCLUDES
#include"vector4.h"
#include<math.h>

void set(vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

float getmagnitude(const vec4* v) {
    const float x = v->x;
    const float y = v->y;
    const float z = v->z;
    const float w = v->w;

    return sqrt(x * x + y * y + z * z + w * w);
}

vec4 normalized(const vec4* v) {
    float m = getmagnitude(v);
    vec4 v1;
    set(&v1, v1.x, v1.y, v1.z, v1.w);
    return v1;
}
