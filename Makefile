include Common.mk

BINDIR := ./bin
SUBDIRS := brainteasers lists strings sorts
TESTS := $(shell find $(BINDIR) -type f -perm +111)

all: build run
.PHONY: all

build: $(SUBDIRS)
.PHONY: build $(SUBDIRS)
$(SUBDIRS):
	-@ echo "\033[00;31m++ Building $@\033[0m" 
	$(MAKE) -j -C $@

run: $(TESTS)
.PHONY: run $(TESTS) 
$(TESTS):
	-@ echo "\033[00;31m++ Running $@\033[0m" ;
	-@ time -p $@

.PHONY: clean
clean:
	$(RM) -rf $(BINDIR) 
