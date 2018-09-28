CC=/usr/local/bin/g++-8
CCFLAGS=-g -Wall
GOFLAGS=
GO=/usr/local/bin/go
BINDIR=../bin

SRC=$(shell ls *.cpp *.go)
brainteasers: $(SRC)
	-@ echo "\033[00;31mCompiling $(SRC)\033[0m"
	GOOS=darwin GOARCH=386 CGO_ENABLED=0 $(GO) build  -o $(BINDIR)/match_go hanoi.go
	$(CC) $(CCFLAGS) -ftemplate-depth=1000 -o $(BINDIR)/fibonacci_cpp fibonacci.cpp