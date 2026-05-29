/// main.c

// INCLUDES
#include<stdio.h>
#include<string.h>
#include"architecture.h"

struct color4 WHITE;
struct color4 BLUE;


int main()
{
	set_color4(&WHITE, 1, 1, 1, 1);
	set_color4(&BLUE, 0, 0, 1, 1);
	const int w = 7680;
	const int h = 4320;
	matsc S1;
	
	init(&S1, w, h);
	printf("%i", S1.res_w);
	fill(&S1, WHITE, w, h);
	slope2color(&S1, WHITE, BLUE, 0.7, 0);
	save(S1, w, h, "matsc.txt");
	
	return 0;
}