CC=gcc
SRC=../src
BIN=../bin/
LIBONT=libontconnection.so
CFLAGS=-fPIC -Wall -std=c99
PATHINCLUDE=./
LDFLAGS=-L./$(PATHINCLUDE) -lontconnection -ltap -Wl,-rpath,$(PATHINCLUDE)
SOURCES=test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

all: $(EXECUTABLE) 
	
$(EXECUTABLE): $(BIN)$(LIBONT) $(OBJECTS) 
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $< -c

$(BIN)$(LIBONT): 
	make -C $(SRC) -r
	mkdir -p $(PATHINCLUDE)
	cp -r $(BIN)* $(PATHINCLUDE)

clean:
	rm $(OBJECTS) $(EXECUTABLE)
	make -C $(SRC) clean
