main:main.c lib/libfoo.so
	gcc   -g -Wall main.c -o main -Wl,-rpath,'$$ORIGIN/lib' -lfoo -L./lib 

lib/libfoo.so:lib/foo.c
	gcc -g -Wall -fPIC -shared -o lib/libfoo.so lib/foo.c
clean:
	rm ./lib/libfoo.so ./main
