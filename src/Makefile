CC=gcc
CFLAGS=-fPIC -Wall -std=c99
LDFLAGS=-shared -nostdlib
PATHSO="../bin/libontconnection.so"
SOURCES=ont.c
HEADERS=ont.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=libontconnection.so

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	mkdir -p ../bin
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(PATHSO)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $< -c 

$(SRCS): $(HEADERS)
	@touch $@

clean:
	rm ont.o
	rm -r ../bin
