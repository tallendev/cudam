all: cudam.so

cudam.so: cudam.cpp safecuda.h Makefile
	nvcc -Xcompiler "-O3 -g -std=c++11 -Wall -Wextra -fpic -shared" -o cudam.so cudam.cpp -lcudart
