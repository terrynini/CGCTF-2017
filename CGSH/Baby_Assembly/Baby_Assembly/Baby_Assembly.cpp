#include "stdafx.h"
#include <stdio.h>
#include <iostream>

int main(void) {
	int tmp = 0;
	int arr[] = { 
		1413695299,
		1750367046,
		1767863145,
		1752457075,
		1920229221,
		1868522869,
		8217966,
		0};

	if (FILE *fp = fopen("./config/CGCTF{is_this_the_flag}.txt", "w")) {
		puts("You did a great job, go to get your flag");

		for (int *ptr = arr; *ptr;) {
			tmp = *(ptr++);
			fprintf(fp, "%.4s", (char *)&tmp);
		}
	}
	else
		puts("sorry, you dont know me :( ");

	system("PAUSE");
	return 0;
}
