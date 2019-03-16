include ../Common.mk

APP := $(shell basename $$(pwd))
SRC := $(shell ls *.cpp)
OBJ=$(subst .cpp,_cpp,$(SRC))

%_cpp : %.cpp
	$(CC) $(CCFLAGS) -o $(BINDIR)/$(APP)/$*_cpp $<

all: dir $(SRC) $(OBJ)
	
dir:
	$(MKDIR) dir -p $(BINDIR)/$(APP)

clean: 
	$(RM) -rf $(BINDIR)/$(APP)