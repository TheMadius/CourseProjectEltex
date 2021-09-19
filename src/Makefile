CC=gcc
CFLAGS=-Wall -std=c99
LDFLAGS=-shared
PATHSO="../bin/libontconnection.so"
SOURCES=ont.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=libontconnection.so

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	mkdir -p ../bin
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(PATHSO)

.c.o:
	$(CC) $(CFLAGS) $< -c 
