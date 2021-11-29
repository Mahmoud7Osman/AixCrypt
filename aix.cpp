#include "pts.h"

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

using namespace std;


int main(int argc, char** argv){
	int   	   opt;
	int    produce;
	int        key;

	char* arguments[5];

	arguments[4]=NULL;

	arguments[1]=argv[1];

	produce=strcmp(argv[2], "produce");
	key=strcmp(argv[2], "keygen");

	while ((opt=getopt(argc, argv, ":f:k:"))!=-1){
		switch(opt){

			case 'f':
				arguments[2]=argv[4];
				break;
			case 'k':
				arguments[3]=argv[6];
				break;
		}
	}
	if (produce==0x00)
		arguments[0]=(char*)XKP;
	else if (key==0x00)
		arguments[0]=(char*)XKK;
	else return fprintf(stderr, "Error: No Operation Was Specified, Generate Key, Or Produce Data, execute ./%s -h\n", argv[0]);

	return execvp(arguments[0], arguments);
}
