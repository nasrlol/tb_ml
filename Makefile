# Build configuration
BIN := build/tb_ml
SRC := source/tb_ml/tb_ml.c
OBJ := build/tb_ml.o
DEP := build/tb_ml.d

# Compiler flags
CC ?= clang
CFLAGS := -Wall -Wextra -Wpedantic -Wno-unused-function -g --std=c99 -fno-omit-frame-pointer
LDFLAGS := -lm

# Optimization level
OPT ?= 0
CFLAGS += -O$(OPT)

# Build directory
$(shell mkdir -p build)

# Targets
.PHONY: all run clean help

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -MT $@ -MMD -MP -MF $(DEP) -c $< -o $@

-include $(DEP)

run: $(BIN)
	./$(BIN)

clean:
	rm -rf build

help:
	@echo "make [OPT=0|1|2|3]"
	@echo "  all    - Build (default)"
	@echo "  run    - Build and run"
	@echo "  clean  - Remove artifacts"
