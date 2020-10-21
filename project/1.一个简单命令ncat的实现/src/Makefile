CC = gcc
CFLAGS = -std=c99 -Wall -Werror
MAINOBJS = ncat.o roman.o
RM = rm -f

.PHONY: clean
ncat: $(MAINOBJS)
	$(CC) $(CFLAGS) -o ncat $(MAINOBJS)
roman.o: roman.c roman.h
	$(CC) $(CFLAGS) -c -o roman.o roman.c
ncat.o: ncat.c roman.h
	$(CC) $(CFLAGS) -c -o ncat.o ncat.c 

clean:
	$(RM) -- *.o ncat
