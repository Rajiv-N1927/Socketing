CC=gcc
CFLAGS=-I.
DEPS = unp.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testcli: testcli.o wrapsock.o err.o
	$(CC) -o testcli testcli.o wrapsock.o err.o
