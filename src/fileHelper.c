#include "fileHelper.h"
#include "stdio.h"
#include "stdlib.h"


//this is gonna need a full rework
const char* loadFile(const char* filename){
	printf("loading file: %s\n", filename);
	FILE *readfile = fopen(filename, "r");


	if(readfile == NULL){
		printf("Failed to load file: %s\n", filename);
		return NULL;
	}
	if(fseek(readfile, 0, SEEK_END) < 0){
		fclose(readfile);
		return NULL;
	}


	//get file size and allocate memory
	long fileSize = ftell(readfile);
	printf("filesize: %ld bytes\n", fileSize);	
	char *ret = malloc(fileSize + 1);
	
	//read file to memory
	for(int index = 0; index < fileSize; index++){
		ret[index] = fgetc(readfile);
		printf("%c",ret[index]);
	}
	ret[fileSize+1] = '\0';


	printf("file contents...: %i", ret);

	fclose(readfile);
	return ret;

}

void saveFile(const char* filename, const char* data){
	FILE *writeFile = fopen(filename, "w");
	fprintf(writeFile, "%s",data);
	fclose(writeFile);
}

