
CC=gcc
CFLAGS=-g -Wall
BINS=tree

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(BINS)