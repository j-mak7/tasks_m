CC=gcc
CFLAGS=-Wall -g
SOURCES=9.c str_to_arr.c check_number.c
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
