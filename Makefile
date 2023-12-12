CC = gcc
CFLAGS = -Wall -Werror

SOURCES = betty_shell.c exec.c fork.c ppid.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = hsh

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): %.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJECTS) $(EXECUTABLE)
