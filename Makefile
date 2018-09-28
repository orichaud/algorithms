all:
	-@ mkdir -p bin
	-@ cd strings && make
	-@ cd brainteasers && make

run: all
	-@ for exec in $$(find ./bin -type f -perm +111); do \
		echo "\033[00;31m++ Running $$exec\033[0m" ; \
		time eval "$$exec" ; \
	done

clean:
	-@ rm -rf bin