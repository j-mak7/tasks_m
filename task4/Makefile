CC=gcc
CFLAGS=-Wall -g
SOURCES=4.c print.c addstr.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=task4

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.c.o:
	$(CC) $< -o $@
