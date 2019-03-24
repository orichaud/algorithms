CC := /usr/local/bin/g++-8
CCFLAGS := -g -O -Wall -Wextra -Werror -std=c++17
LDFLAGS :=
LDLIBS :=
GO := /usr/local/bin/go
GOFLAGS := 
BINDIR := ../bin
MAKE := /usr/bin/make
RM := rm
MV := mv
MKDIR := mkdir

APP := $(shell basename $$(pwd))
SRC := $(shell ls *.cpp *.go 2>/dev/null)
OBJ=$(subst .cpp,_cpp,$(SRC)) $(subst .go,_go,$(SRC))

%_go : %.go
	GOOS=darwin GOARCH=386 CGO_ENABLED=0 $(GO) build $< && $(MV) $* $(BINDIR)/$(APP)/$*_go

%_cpp : %.cpp
	$(CC) $(CCFLAGS) -o $(BINDIR)/$(APP)/$*_cpp $(LDFLAGS) $(LDLIBS) $< 

all: dir $(SRC) $(OBJ)
	
dir:
	$(MKDIR) -p $(BINDIR)/$(APP)

clean: 
	$(RM) -rf $(BINDIR)/$(APP)