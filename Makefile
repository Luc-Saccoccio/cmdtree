CC=tcc
CFLAGS=-O2 -g -Wall -Werror -I. -Wno-unused-function -I/usr/include/freetype2
LDFLAGS=-lXft -lfontconfig -lX11
PREFIX ?= /usr/local

SRC= drw.c cmdtree.c util.c command.c
OBJ = ${SRC:.c=.o}

all: options cmdtree

options:
	@echo cmdtree build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h

config.h:
	cp config.def.h $@


cmdtree: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f ${OBJ} cmdtree

install: cmdtree
	mkdir -p ${PREFIX}/bin
	cp cmdtree ${PREFIX}/bin

uninstall:
	rm -f ${PREFIX}/bin/cmdtree
