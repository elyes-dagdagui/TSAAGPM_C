/// matscreen.c

// INCLUDES
#include"matscreen.h"
#include<stdio.h>
#include<stdlib.h>

void init(matsc* M,const int res_w, const int res_h) {
	M->res_w = res_w;
	M->res_h = res_h;
	M->pixels = (struct color4**)malloc(res_h * sizeof(struct color4*));
	if (M->pixels == NULL) {
		perror("malloc failed for rows");
	}
	for (int i = 0; i < res_h; i++) {
		M->pixels[i] = (struct color4*)malloc(res_w * sizeof(struct color4));
		if (M->pixels[i] == NULL) {
			perror("malloc failed for columns");
		}
	}
	
}

void fill(matsc *M, struct color4 color, int res_w, int res_h) {
	for (int i = 0; i < res_h; i++) {
		for (int k = 0; k < res_w; k++) {
			M->pixels[i][k] = color;
		}
	}
}

void save(matsc M, int res_w, int res_h, char* name) {
	FILE* fptr;
	fptr = fopen(name, "w");
	char l[(res_w*2)+1];
	
	for (int i = 0; i < res_h; i++) {
		int k, j = 0;
		for (k = 0; k < (res_w * 2) + 1; k = k + 2, j++) {
			struct color4 v;
			set_color4(&v, M.pixels[i][j].r,
				M.pixels[i][j].g, 
				M.pixels[i][j].b, 
				M.pixels[i][j].a
			);
			float x = fbrightness(v);
			if (x >= 0.75f) {
				l[k] = '#';
			}
			else if (x >= 0.5f) {
				l[k] = '+';
			}
			else if (x >= 0.25f) {
				l[k] = '-';
			}
			else {
				l[k] = '.';
			}
			l[k + 1] = ' ';
		}
		l[res_w * 2] = '\0';
		fputs(l, fptr);
		//fputs("\n", fptr);
	}
	fclose(fptr);
}