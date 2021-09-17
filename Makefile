build: base.o init.o list.o
	gcc -shared base.o init.o list.o -o ./bin/libontconnection.so
base.o:
	gcc -fPIC -c ./src/base.c
init.o:
		gcc -fPIC -c ./src/init.c
list.o:
	gcc -fPIC -c ./src/list.c
clean: 
	rm init.o list.o base.o