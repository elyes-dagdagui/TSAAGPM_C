/// vector4.h

// INCLUDES
#include"architecture.h"

#ifndef vector4_h
#define vector4_h

struct vector4
{
    float x;
    float y;
    float z;
    float w;
};

typedef struct vector4 vec4;

CORE_API void set(vec4* v, float x, float y, float z, float w);
CORE_API float getmagnitude(const vec4* v);
CORE_API vec4 normalized(const vec4* v);
#endif