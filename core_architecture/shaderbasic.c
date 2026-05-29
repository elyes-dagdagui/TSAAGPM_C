/// shaderbasic.c

// INCLUDES
#include"shaderbasic.h"
#include"motionfs.h"

struct color4 RGBA_EXP_LERP_ROUTINE(struct color4 color1, struct color4 color2, float slope, float x) {
	struct color4 color3;
	color3.r = exp_lerp_routine(color1.r, color2.r, slope, x);
	color3.g = exp_lerp_routine(color1.g, color2.g, slope, x);
	color3.b = exp_lerp_routine(color1.b, color2.b, slope, x);
	color3.a = exp_lerp_routine(color1.a, color2.a, slope, x);
	return color3;
}

void slope2color(matsc* screen, struct color4 color1, struct color4 color2, float slope, int dir)
{
	// Vertical Direction
	if (dir == 0)
	{
		for (int i = 0; i < screen->res_w; i++) {
			float x = 0;
			for (int k = 0; k < screen->res_h; k++) {
				screen->pixels[k][i] = RGBA_EXP_LERP_ROUTINE(color1, color2, slope, x);
				x = x + EPS;
			}
		}
	}
	// Horizontal Direction
	else if (dir == 3) {
		for (int i = 0; i < screen->res_h; i++) {
			float x = 0;
			for (int k = 0; k < screen->res_w; k++) {
				screen->pixels[i][k] = RGBA_EXP_LERP_ROUTINE(color1, color2, slope, x);
				x = x + EPS;
			}
		}
	}
	// Diagonal top-left to bottom-right
	else if (dir == 2) {
		int v = 0;
		for (int i = screen->res_h; i > -1; i--) {
			int j = i;
			float x = 0;
			for (int k = 0; k < v; k++) {
				screen->pixels[j][k] = RGBA_EXP_LERP_ROUTINE(color1, color2, slope, x);
				x = x + EPS;
				j++;
			}
			v++;
		}
		v = screen->res_w - 1;
		for (int i = 1; i < screen->res_w; i++) {
			int j = i;
			float x = 0;
			for (int k = 0; k < v; k++) {
				screen->pixels[k][j] = RGBA_EXP_LERP_ROUTINE(color1, color2, slope, x);
				x = x + EPS;
				j++;
			}
			v -= 1;
		}
	}
}