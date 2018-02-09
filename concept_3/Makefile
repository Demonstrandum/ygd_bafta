COMP   = g++
FLAGS  = -Wall -Wpedantic -lSDL2 -Ilib -O3
TARGET = ./bin/game
GLOB   = /usr/local/bin

all:
	@echo "Compiling $(TARGET).cr..."
	$(COMP) $(FLAGS) ./lib/*/*.cpp ./src/*.cpp ./src/**/*.cpp -o $(TARGET)

install:
	@echo "Copying $(TARGET) to $(GLOB)..."
	cp $(TARGET) $(GLOB)

clean:
	@echo "Removing '$(TARGET)' binary from current directory"
	rm -f $(TARGET)

uninstall:
	@echo "Removing binary from $(GLOB)"
	rm -f $(GLOB)/$(TARGET)
