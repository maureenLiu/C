CC = gcc
CFLAGS = -std=c99 -g -Wall -Wextra
RM = rm -f
OBJS = oj.o run.o

.PHONY: clean

oj: $(OBJS)
	$(CC) $(CFLAGS) -o oj $(OBJS)
oj.o: run.h oj.c
	$(CC) $(CFLAGS) -c -o oj.o oj.c

run.o: run.h run.c
	$(CC) $(CFLAGS) -c -o run.o run.c

clean:
	$(RM) -- $(OBJS) oj 
