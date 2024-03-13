#include "fileHelper.h"
#include "stdio.h"
#include "stdlib.h"


//this is gonna need a full rework
const char* loadFile(const char* filename){
	printf("loading file: %s\n", filename);

	return NULL;

}

void saveFile(const char* filename, const char* data){
	FILE *writeFile = fopen(filename, "w");
	fprintf(writeFile, "%s",data);
	fclose(writeFile);

}

