CC=/usr/local/bin/g++-8
CCFLAGS=-g -Wall
GOFLAGS=
GO=/usr/local/bin/go
BINDIR=../bin

SRC=$(shell ls *.cpp)
brainteasers: $(SRC)
	-@ echo "\033[00;31mCompiling $(SRC)\033[0m"
	$(CC) $(CCFLAGS) -o $(BINDIR)/remove_node_cpp remove_node.cpp
	$(CC) $(CCFLAGS) -o $(BINDIR)/tree_builder_cpp tree_builder.cpp