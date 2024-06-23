# Compiler
CC = gcc

# Directories
SRCDIR = ./src
INCDIR = ./inc
BLDDIR = ./bld

# Files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BLDDIR)/%.o, $(SOURCES))
DEPS = $(patsubst $(SRCDIR)/%.c, $(BLDDIR)/%.d, $(SOURCES))

# Flags
CFLAGS = -I$(INCDIR) -Wall -g
DEPFLAGS = -MMD -MP

# Target executable
TARGET = LIN

# Default rule
all: $(BLDDIR)/$(TARGET)
	@echo "Build successful!"

# Build target
$(BLDDIR)/$(TARGET): $(OBJECTS)
	@echo "Linking $(TARGET)..."
	$(CC) $(OBJECTS) -o $@
	@echo "Build successful!"

# Build objects and dependencies
$(BLDDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling $<..."
	@mkdir -p $(BLDDIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

# Include dependencies
-include $(DEPS)

# Clean build files
clean:
	rm -f $(BLDDIR)/*.o $(BLDDIR)/$(TARGET) $(BLDDIR)/*.d
	@echo "Clean successful!"

.PHONY: clean

# Rebuild dependencies if the Makefile changes
$(DEPS): Makefile
