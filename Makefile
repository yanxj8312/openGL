CXX = g++
EXEC = SolarSystem
SOURCES = main.cpp star.cpp SolarSystem.cpp
OBJECTS = main.o star.o SolarSystem.o
LDFLAGS = -lglut -lGL -lGLU

all:
	$(CXX) $(SOURCES) $(LDFLAGS) -o $(EXEC)

clean:
	rm -f $(EXEC) *.gdb *.o
