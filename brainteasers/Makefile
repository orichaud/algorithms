include ../Common.mk

APP := $(shell basename $$(pwd))
SRC := $(shell ls *.cpp *.go)
OBJ=$(subst .cpp,_cpp,$(SRC)) $(subst .go,_go,$(SRC))

%_cpp : %.cpp
	$(CC) $(CCFLAGS) -o $(BINDIR)/$(APP)/$*_cpp $<

%_go : %.go
	GOOS=darwin GOARCH=386 CGO_ENABLED=0 $(GO) build $< && $(MV) $* $(BINDIR)/$(APP)/$*_go

all: dir $(SRC) $(OBJ)
	
dir:
	$(MKDIR) -p $(BINDIR)/$(APP)

clean: 
	$(RM) -rf $(BINDIR)/$(APP)