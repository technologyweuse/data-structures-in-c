CC=gcc
CFLAGS=-c -Wall --std=c11
LDFLAGS=

SOURCES=double_linked_list_demo.c
EXECUTABLE=double_linked_list_demo

OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf $(EXECUTABLE)
