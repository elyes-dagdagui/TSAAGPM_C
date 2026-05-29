/// matscreen.h

// INCLUDES
#include"color4.h"
#include"architecture.h"

#ifndef matscreen_h
#define matscreen_h
#define MAX_RES_W 7680
#define MAX_RES_H 4320
struct matscreen
{
	int res_w;
	int res_h;
	struct color4 **pixels;
};

typedef struct matscreen matsc;

CORE_API void init(matsc *M, int res_w, int res_h);
CORE_API void fill(matsc *M, struct color4 color, int res_w, int res_h);
CORE_API void save(matsc M, int res_w, int res_h, char* name);
#endif