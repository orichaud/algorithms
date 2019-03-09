CC=/usr/local/bin/g++-8
CCFLAGS=-g -Wall
BINDIR=../bin

SRC=$(shell ls *.cpp)
all: $(SRC)
	-@ echo "\033[00;31mCompiling $(SRC)\033[0m"
	$(CC) $(CCFLAGS) -o $(BINDIR)/insertion_sort_cpp insertion_sort.cpp
	$
