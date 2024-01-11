CC = gcc
CFLAGS = -Wall -Wextra

SRC_FILES = $(wildcard *.c)
EXECUTABLES = $(patsubst %.c,%,$(SRC_FILES))

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)
