CC=/usr/local/bin/g++-8
CCFLAGS=-g -Wall
GOFLAGS=
GO=/usr/local/bin/go
BINDIR=../bin

SRC=$(shell ls *.cpp *.go)
all: $(SRC)
	-@ echo "\033[00;31mCompiling $(SRC)\033[0m"
	$(CC) $(CCFLAGS) -o $(BINDIR)/match_cpp match.cpp
	$(CC) $(CCFLAGS) -o $(BINDIR)/match_cpp unique.cpp
	$(CC) $(CCFLAGS) -o $(BINDIR)/reverse_cpp reverse.cpp
	$(CC) $(CCFLAGS) -o $(BINDIR)/duplicate_cpp duplicate.cpp
	$(CC) $(CCFLAGS) -o $(BINDIR)/anagram_cpp anagram.cpp
	GOOS=darwin GOARCH=386 CGO_ENABLED=0 $(GO) build  -o $(BINDIR)/match_go match.go

