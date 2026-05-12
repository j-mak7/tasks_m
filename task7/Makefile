CC=gcc
CFLAGS=-Wall -g
SOURCES=7.c copy.c print.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=task7

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.c.o:
	$(CC) $< -o $@
