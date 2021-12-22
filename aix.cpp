#include "pts.h"

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

using namespace std;

const char* help=
"AixCrypt: A Steganography-Like Technique Performed By Doing A Very Simple Calculation on Your Data With Another File, Resulting in a Key Used For Later Production Of Your Exact Data.\n"
"       Usage:   aix  [filename]  [keygen|produce]  -f [File]  -k [Key File]\n\n"
"               First Argument: [filename], used to calculate a key (keygen) or produce data (produce).\n"
"                                Caution: If Your using produce on a [filename] that contain data, all those data will be lost.\n\n"
"		Second Argument:  keygen, keygen is used to calculate key for an exsisting [filename], and output the key into [Key File]\n"
"			         produce, produce is used to produce data into [filename], by calculating The same file [File] Used in keygen, with an exsisting key.\n\n"
"		3rd Argument:    [file], [File], Used to calculate Or Produce data (keygen or produce) to/with the keyfile, (Easy, keygen need to write key into the Keyfile, produce need to read the keyfile to produce actual data)\n\n"
"		4rd Argument:    [Keyfile], [Keyfile] is used to read/write key, keygen need to write a new key, produce need to read then calculate, easy.\n\n"
"	example:\n"
"		$ cd AixCrypt/learn\n"
"		$ cat README.md\n"
"		  ...\n"
"		$ aix produce message -f hello.png -k my_key.txt\n"
"		$ cat message\n"
"		  ...\n"
"	So Easy To Use, see the example, try it yourself in AixCrypt/learn\n";

int main(int argc, char** argv){

	if (argc<6||*(argv[1]+1)=='h') return fprintf(stderr, help);

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
