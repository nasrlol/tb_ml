# Build configuration
BIN := build/tb_ml
SRC := source/tb_ml/tb_ml.c
OBJ := build/tb_ml.o

# Compiler
CC ?= gcc

# Flags
CFLAGS := -Wall -Wextra -Wpedantic -Wno-unused-function -g --std=c99 -fno-omit-frame-pointer -Wno-unused-variable
LDFLAGS := -lm

# Optimization level
OPT ?= 3
CFLAGS += -O$(OPT)

# Targets
.PHONY: all run clean help

all: clean $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(OBJ): $(SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(BIN)

clean:
	rm -rf build

help:
	@echo "make [OPT=0|1|2|3]"
	@echo "  all    - Clean and build (always recompiles)"
	@echo "  run    - Clean, build, and run"
	@echo "  clean  - Remove artifacts"
