CC=gcc
CFLAGS=-fPIC -Wall -std=c99
LDFLAGS=-shared -nostdlib
PATHSO="../bin/lib/libontconnection.so"
SOURCES=ont.c
HEADERS=ont.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=libontconnection.so

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	mkdir -p ../bin/include
	mkdir -p ../bin/lib
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(PATHSO)
	cp $(HEADERS) ../bin/include

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $< -c 

$(SRCS): $(HEADERS)
	@touch $@

clean:
	rm ont.o
	rm -r ../bin
