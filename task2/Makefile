CC=gcc
CFLAGS=-Wall -g
SOURCES=2.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=task2

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.c.o:
	$(CC) $< -o $@
