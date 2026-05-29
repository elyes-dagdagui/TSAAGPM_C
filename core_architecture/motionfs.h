#pragma once
#ifndef motionprocessing_h
#define motionprocessing_h
#define e 2.718281828459045235360

float expdecay(float a1, float a2, float r, float x);
float expamplifier(float a1, float a2, float r, float x);
float exp_lerp_routine(float a1, float a2, float r, float x);

#endif