# Compiler and flags
CXX = g++

# Relative SFML paths
SFML_INCLUDE = ./sfml/include
SFML_LIB = ./sfml/lib

CXXFLAGS = -std=c++11 -I$(SFML_INCLUDE)
LDFLAGS = -L$(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = Main.cpp Game.cpp Player.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = knucklebones

# Default rule
all: $(TARGET)

# Linking rule
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compilation rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
