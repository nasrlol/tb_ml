BIN := build/tb_ml
SRC := source/tb_ml/tb_ml.c

CC ?= gcc
CFLAGS :=  -Wno-attributes \
          -fno-omit-frame-pointer -Wno-unused-variable \
          -Wno-unused-function -fno-asynchronous-unwind-tables \
          -ftime-report -O0 --std=c99 -g
LDFLAGS := -lm

.PHONY: all run clean help

all: clean $(BIN)

$(BIN): $(SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

run: all
	./$(BIN)

clean:
	rm -rf build


