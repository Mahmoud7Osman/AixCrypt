#!/bin/bash
echo
sleep 1
printf "[ProTip] It's Better to Run this script as root, in order to execute this program by typing only aix into the cmd line without the path\n"
echo
sleep 1
build(){
	printf "Building Binaries..\n"
	mkdir ~/.aix 2>/dev/null
	g++ src/AixCrypt.cpp -o ~/.aix/XKgenerate
	g++ src/AixDecrypt.cpp -o ~/.aix/XKproducer
}
preprocess(){
	printf "Generating Preprocessor's Instruction Required For Compiling aix command\n"
	printf "#define XKP "'"'"$HOME/.aix/XKproducer"'"'"\n" >  pts.h
	printf "#define XKK "'"'"$HOME/.aix/XKgenerate"'"'"\n" >> pts.h
}

build
preprocess

g++ aix.cpp -o aix

if [ $(whoami) == "root" ];then
  cp aix /bin/aix
  printf "Succeed, You can now run this program by typing aix in your terminal\n"
else
  printf "You Can Copy ./aix to /bin to use it without full path (Or Any directory you Prefer presented in the PATH Variable)\n"
fi
