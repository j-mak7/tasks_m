CC=gcc
CFLAGS=-Wall -g -D_GNU_SOURCE
SOURCES=5.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=task5

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.c.o:
	$(CC) $< -o $@
