CC=gcc
CFLAGS=-Werror=all -Werror=extra -pedantic\
                  -Wno-error=format-nonliteral -Wformat-nonliteral \
                  -Werror=write-strings \
                  -Wno-error=discarded-qualifiers -Wno-error=incompatible-pointer-types \
                  -Wno-clobbered \
                  -fPIE -fstack-protector-all -ftrapv -D_FORTIFY_SOURCE=2 \
                  -Wl,-z,relro,-z,now -Wl,-z,noexecstack \
                  -Wbad-function-cast -Wcast-align -Werror=cast-qual -Wconversion \
                  -Werror=float-equal -Wformat-security -Werror=format-overflow=2 -Wformat-truncation \
                  -Winline -Winvalid-pch -Werror=jump-misses-init -Wlogical-op -Wmissing-declarations \
                  -Wmissing-prototypes -Wnested-externs -Wold-style-definition \
                  -Woverlength-strings -Werror=redundant-decls -Werror=shadow -Werror=strict-overflow=5 \
                  -Wsuggest-attribute=const -Werror=switch-default -Wtrampolines \
                  -Werror=undef \
                  -Werror=unused -Werror=stringop-overflow=4 -Wdeclaration-after-statement
LDFLAGS=-shared -nostdlib
PATHL=../bin/
PATHINC=../include
NAMEL=libontconnection.so
SOURCES=ont.c
HEADERS=ont.h
OBJECTS=$(SOURCES:.c=.o)

all: $(NAMEL)
	
$(NAMEL): $(OBJECTS)
	mkdir -p $(PATHL)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(PATHL)$(NAMEL)
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
