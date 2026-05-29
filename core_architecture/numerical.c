/// numerical.c

// INCLUDES
#include<string.h>
#include<stdio.h>
#include"numerical.h"
#include<stdlib.h>

const char HEX[] = "0123456789ABCDEF";

void C_B10_B16(int dec,char* hex) {
	char temp[3];
	int i = 0;
	if (dec == 0) {
		strcpy(hex, "0");
		return;
	}

	while (dec > 0) {
		temp[i] = HEX[dec % 16];
		dec /= 16;
		i++;
	}

	// reverse
	for (int j = 0; j < i; j++) {
		hex[j] = temp[i - j - 1];
	}

	hex[i] = '\0';
}