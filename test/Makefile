CC=gcc
CFLAGS=-fPIC -Wall -std=c99
LDFLAGS=-L../include -ltap -Wl,-rpath,$(pwd)/../include
SOURCES=test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $< -c

clean:
	rm $(OBJECTS) $(EXECUTABLE)
