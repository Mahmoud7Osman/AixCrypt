#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main(int argc, char** argv){
	int   	   opt;
	int    	     i;
	int    produce;
	int        key;

	char* arguments[4];

        if (open(argv[1], O_RDONLY)<0){
                cerr << "Error: Command Line Arguments Missing or Not Specified Correctly.\nExecute With -h For Help\n";
		return 1;
        }
	arguments[1]=argv[1];

	produce=strcmp(argv[2], "produce");
	key=strcmp(argv[2], "key");

	while ((opt=getopt(argc, argv, ":f:k:"))!=-1){
		printf ("Running\n");
		switch(opt){
			case 'f':
				arguments[2]=argv[i+1];
				printf ("Fucking\n");
			case 'k':
				arguments[3]=argv[i+1];
		}
		i++;
	}
	if (produce==0x00)
		arguments[0]=(char*)"XKgenerate";
	else if (key==0x00)
		arguments[0]=(char*)"XKproducer";
	else return fprintf(stderr, "Error: No Operation Was Specified, Generate Key, Or Produce Data, execute ./%s -h\n", argv[0]);

	return execve(arguments[0], arguments, NULL);
}
