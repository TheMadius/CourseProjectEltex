CC=gcc
CFLAGS=-fPIC
LDFLAGS=-shared -nostdlib
FLAGL=-lpthread
PATHL=../bin/
PATHINC=../include
NAMEL=libontconnection.so
SOURCES=ont.c
HEADERS=ont.h
OBJECTS=$(SOURCES:.c=.o)

all: $(NAMEL)
	
$(NAMEL): $(OBJECTS)
	mkdir -p $(PATHL)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(PATHL)$(NAMEL) $(FLAGL)
	cp $(HEADERS) $(PATHINC)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $< -c

$(SRCS): $(HEADERS)
	@touch $@

clean:
	rm $(OBJECTS)
	rm -r $(PATHL)
