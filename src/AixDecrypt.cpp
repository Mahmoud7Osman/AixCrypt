/*
 * How The Algorithm Work ?
 *	The Process Of Decrypting another file into our original file:
 *			- Claculating The Key For Every Byte
 *			- Adding OR Substracting Key From Files
 *	This Was It Only !! Wanna Learn More About That ?? Read The Source Code !.
 */

#include <iostream>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>


int main(int argc, char** argv){
	if (argc < 3){
	   return 1;
	}

	int ffd;  // Original File's Descriptor To Which We Will Reproduce Data From Key And AsFile.
	int afd;  // The File We Need to Create a key to decrypt it into the Original File
	int kfd;  // Key File.

	char *fdata, *byte1;
	char *adata, *byte2;
	char   *key, *byte3;

	struct stat file;
	struct stat asfile;

	ffd=open(argv[1], O_WRONLY | O_TRUNC | O_CREAT);
	afd=open(argv[2], O_RDONLY);
	kfd=open(argv[3], O_RDONLY);

	if (ffd == -1 || afd == -1 || kfd == -1)
		return fprintf(stderr, "(Error) Opening Files\n");

	stat(argv[3], &file);
	stat(argv[2], &asfile);

	if (file.st_size > asfile.st_size){
		return fprintf(stderr, "(Error) The 'As' File size is smaller than the Key file\n");
	}

	fdata=(char*)malloc(file.st_size);
	adata=(char*)malloc(asfile.st_size);
	key=(char*)malloc(file.st_size);

	byte1=fdata;
	byte2=adata;
	byte3=key;


	if (read(kfd, key, file.st_size) != file.st_size || read(afd, adata, asfile.st_size) != asfile.st_size){
		return fprintf(stderr, "(Error) Wrong Size Was Read From Specified Files\n");
	}

	for (int size=0; size<=file.st_size; size++){
		*byte1++=*byte2+++*byte3++;
	}

	write(ffd, fdata, file.st_size);

	close(ffd);
	close(afd);
	close(kfd);

	free(fdata);
	free(adata);
	free(key);
}
