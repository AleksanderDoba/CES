CC = g++
CFLAGS = -c -Wall
LDFLAGS = 
SOURCES = position_component.cpp velocity_component.cpp movement_system.cpp example.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = example

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o example
