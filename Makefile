# Makefile

include sources.mk

# Define variables
TARGET = c1m2.out
MAP_FILE = c1m2.map

# Compiler and linker flags
CPPFLAGS =
CFLAGS = -Wall -Werror -g -O0 -std=c99 $(CPPFLAGS)

ifeq ($(PLATFORM),MSP432)
    CC = arm-none-eabi-gcc
    INCLUDES = -Iinclude/common -Iinclude/msp432 -Iinclude/CMSIS
    LDFLAGS = -T msp432p401r.lds
    ARCH_FLAGS = -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
    CFLAGS += $(INCLUDES) -DMSP432 $(ARCH_FLAGS)
else
    CC = gcc
    INCLUDES = -Iinclude/common
    LDFLAGS =
    ARCH_FLAGS =
    CFLAGS += $(INCLUDES) -DHOST $(ARCH_FLAGS)
endif

LDFLAGS += $(ARCH_FLAGS) -Wl,-Map=$(MAP_FILE)

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Default target
.PHONY: all
all: build

# Build target
.PHONY: build
build: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile all object files but do not link
.PHONY: compile-all
compile-all: $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Generate the preprocessed output of all c-program implementation files
%.i: %.c
	$(CC) $(CFLAGS) -E $< -o $@

# Generate assembly output of c-program implementation files
%.asm: %.c
	$(CC) $(CFLAGS) -S $< -o $@

# Clean target
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TARGET) $(MAP_FILE) *.i *.asm *.d
