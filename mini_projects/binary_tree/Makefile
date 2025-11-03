
CC=gcc
CFLAGS=-g -Wall
BINS=treexample

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(BINS)