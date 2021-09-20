CC=gcc
CFLAGS=-fPIC -Wall -std=c99
LDFLAGS=-shared -nostdlib
PATHL=../bin/
NAMEL=libontconnection.so
SOURCES=ont.c
HEADERS=ont.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=libontconnection.so

all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	mkdir -p $(PATHL)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(PATHL)$(NAMEL)
	cp $(HEADERS) $(PATHL)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $< -c 

$(SRCS): $(HEADERS)
	@touch $@

clean:
	rm $(OBJECTS)
	rm -r $(PATHL)
