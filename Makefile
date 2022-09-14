all: cudam.so

cudam.so: cudam.cpp safecuda.h Makefile
	g++ -O3 -g -std=c++11 -o cudam.so -fpic -shared -Wall -Wextra cudam.cpp -lcudart
