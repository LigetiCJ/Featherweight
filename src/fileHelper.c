#include "fileHelper.h"
#include "stdio.h"
#include "stdlib.h"

const char* loadFile(const char* filename){
	printf("loading file: %s\n", filename);

	FILE * readFile = fopen(filename, "r");
	if(!readFile){
		printf("failed to load file:%s", filename);
		exit(22);
	}
	
	//find size of file
	fseek(readFile, 0, SEEK_END);
	int fileSize = ftell(readFile);
	fseek(readFile, 0, SEEK_SET);
	
	//allocate memory for the string (REMEMBER TO FREE THIS LATER)
	char *str = (char*)malloc(sizeof(char) * fileSize) + 1;
	
	//iterate over the file sucking the bytes out the harddrive
	int index = 0;
	do{
		str[index] = fgetc(readFile);
		index++;
	}while(str[index-1] != -1);
	
	//null terminate the string (opengl hates when you forget this)
	str[index-1] = 0;
		
	//close filestream
	fclose(readFile);
	return str;

}

/*
void loadModel(const char* filename, float *points, int *faces){
	FILE *readFile = fopen(filename, "r");
	if(!readFile){
		exit(23);
	}
	
	int maxPoints = 512;
	points = malloc(sizeof(float)*maxPoints);
	faces = malloc(sizeof(int)*maxPoints);
	
	
}*/

