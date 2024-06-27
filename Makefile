# Compiler
CC = gcc

# Directories
SRCDIR = ./src
INCDIR = ./inc
CFGDIRECTORY = ./cfg
BLDDIR = ./bld

# Files
SOURCES = $(wildcard $(SRCDIR)/*.c) $(wildcard $(CFGDIRECTORY)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BLDDIR)/%.o, $(SOURCES))
OBJECTS := $(patsubst $(CFGDIRECTORY)/%.c, $(BLDDIR)/%.o, $(OBJECTS))
DEPS = $(patsubst $(SRCDIR)/%.c, $(BLDDIR)/%.d, $(SOURCES))
DEPS := $(patsubst $(CFGDIRECTORY)/%.c, $(BLDDIR)/%.d, $(DEPS))

# Flags
CFLAGS = -I$(INCDIR) -I$(CFGDIRECTORY) -Wall -g
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
	mkdir -p $(BLDDIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(BLDDIR)/%.o: $(CFGDIRECTORY)/%.c
	@echo "Compiling $<..."
	mkdir -p $(BLDDIR)
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
