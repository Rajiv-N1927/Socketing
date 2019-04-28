CC=gcc
CFLAGS=-I.
DEPS = unp.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	@echo $(value @)
	@echo $(value <)

WRAPPERS=$(wildcard lib/wrap*.c)
OBJS=$(WRAPPERS:.c=.o)

testcli: testcli.o error.o $(OBJS)
	$(CC) -o testcli testcli.o error.o $(OBJS)


testserv: testserv.o error.o $(OBJS)
	$(CC) -o testserv testserv.o error.o $(OBJS)

all: testcli testserv
