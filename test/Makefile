CC=gcc
CFLAGS=-fPIC -Wall -std=c99
LDFLAGS=-L../include -ltap -Wl,-rpath,$(PWD)/../include
SOURCES=test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $< -c

clean:
	rm $(OBJECTS) $(EXECUTABLE)
