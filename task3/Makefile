CC=gcc
CFLAGS=-Wall -g
SOURCES=3.c sort.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=task3

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.c.o:
	$(CC) $< -o $@
