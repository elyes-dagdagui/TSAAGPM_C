/// shaderbasic.h

#pragma once

// INCLUDES
#include"color4.h"
#include"matscreen.h"
#include"architecture.h"

#ifndef shaderbasic_h
#define shaderbasic_h
#define EPS 0.01

struct color4 RGBA_EXP_LERP_ROUTINE(struct color4 color1, struct color4 color2, float slope, float x);
CORE_API void slope2color(matsc* screen, struct color4 color1, struct color4 color2, float slope, int dir);

#endif