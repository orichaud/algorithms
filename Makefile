include Common.mk

BINDIR := ./bin

all: $(SUBDIRS)

$(SUBDIRS):
	-@ echo "\033[00;31m++ Building $@\033[0m" ; \
	$(MAKE) -C $@

.PHONY: all $(SUBDIRS)

run: all 
	-@ for exec in $$(find $(BINDIR) -type f -perm +111); do \
		echo "\033[00;31m++ Running $$exec\033[0m" ; \
		time eval "$$exec" ; \
	done

clean:
	$(RM) -rf $(BINDIR) 
