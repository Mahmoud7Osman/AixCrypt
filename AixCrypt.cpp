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


void dbg(){
   fflush(stdout);
   return (void)printf("[DEBUG]\n");
}

int main(int argc, char** argv){
	if (argc < 3){
	   return fprintf(stderr, "Usage: %s <file> --as pct.jpg --key mykey.txt\n");
	}

	int ffd;  // Original File Used For Key Calculation for the 'As' File
	int afd;  // The File We Need to Create a key to decrypt it into the Original File
	int kfd;  // Key File.
dbg();
	char *fdata, *byte1;
	char *adata, *byte2;
	char   *key, *byte3;

	struct stat file;
	struct stat asfile;

	ffd=open(argv[1], O_RDONLY);
	afd=open(argv[2], O_RDONLY);
	kfd=open(argv[3], O_WRONLY | O_CREAT | O_TRUNC);

	if (ffd == -1 || afd == -1 || kfd == -1)
		return fprintf(stderr, "(Error) Opening Files\n");

	stat(argv[1], &file);
	stat(argv[2], &asfile);
dbg();
	if (file.st_size > asfile.st_size){
		return fprintf(stderr, "(Error) The 'As' File size is smaller than the original file\n");
	}
dbg();
	printf ("%d\n%d\n%d\n", file.st_size, asfile.st_size, file.st_size);
dbg();
	fdata=(char*)malloc(file.st_size);
	adata=(char*)malloc(asfile.st_size);
	key=(char*)malloc(file.st_size);

	byte1=fdata;
	byte2=adata;
	byte3=key;

dbg();
	if (read(ffd, fdata, file.st_size) != file.st_size || read(afd, adata, asfile.st_size) != asfile.st_size){
		return fprintf(stderr, "(Error) Wrong Size Was Read From Specified Files\n");
	}
dbg();
	for (int size=0; size<=file.st_size; size++){
		*byte3=*byte1-*byte2;
		byte1++;byte2++;byte3++;
	}
dbg();
	write(kfd, key, file.st_size);

	close(ffd);
	close(afd);
	close(kfd);

	free(fdata);
	free(adata);
	free(key);
}
