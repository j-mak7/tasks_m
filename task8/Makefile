CC=gcc
CFLAGS=-Wall -g
SOURCES=8.c generate_matr.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=task8

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.c.o:
	$(CC) $< -o $@
