#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	FILE* fp = fopen("nand.txt", "w");
	
	for (int i  =0; i < 100; i++) {
		char line[100];
		sprintf(line, "[%02d]\n", i);
		fputs(line, fp);
	}
	fclose(fp);
	return 0;
}
