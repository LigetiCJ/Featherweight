#include "fileHelper.h"
#include "stdio.h"
#include "stdlib.h"


//this is gonna need a full rework
const char* loadTextFile(const char* filename){
	printf("loading file: %s\n", filename);
	FILE *readfile = fopen(filename, "rb");
	char* ret;

	if(readfile == NULL){
		return NULL;
	}

	fseek(readfile, 0, SEEK_END);
	long fileSize = ftell(readfile); 
	rewind(readfile);

	ret = (char*)malloc(fileSize + 1);
	
	fread(ret, 1, fileSize, readfile);

	fclose(readfile);
	return ret;

}

void saveFile(const char* filename, const char* data){
	FILE *writeFile = fopen(filename, "w");
	fprintf(writeFile, "%s", data);
	fclose(writeFile);
}

