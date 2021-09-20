CC=gcc
SRC=../src
PATHL=$(PWD)/../include=
BIN=../bin/
LIBONT=libontconnection.so
CFLAGS=-fPIC -Wall -std=c99
LDFLAGS=-L../include -ltap -Wl,-rpath,$(PATHINCLUDE)
PATHINCLUDE=include
SOURCES=test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

all: $(EXECUTABLE) 
	
$(EXECUTABLE): $(OBJECTS) $(BIN)$(LIBONT)
	mkdir -p $(PATHINCLUDE)
	cp $(PATHL)/libtap.so $(PATHINCLUDE) 
	cp -r $(BIN)* $(PATHINCLUDE)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $< -c

$(BIN)$(LIBONT): 
	make -C $(SRC) -r

clean:
	rm -r $(PATHINCLUDE)
	rm $(OBJECTS) $(EXECUTABLE)
	make -C $(SRC) clean
