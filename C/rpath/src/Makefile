main:main.c lib/libfoo.so
	gcc   -g -Wall main.c -o main -lfoo -Wl,-rpath,'$$ORIGIN/lib' -L${shell pwd}/lib 
lib/libfoo.so:lib/foo.c
	gcc -g -Wall -fPIC -shared -o lib/libfoo.so lib/foo.c
clean:
	rm ./lib/libfoo.so ./main
