BIN := build/tb_ml
SRC := source/tb_ml/tb_ml.c

CC ?= clang

CFLAGS :=                                    \
-Wall -Wextra -Wpedantic                     \
-Wno-unused-function 						 \
--std=c99            						 \
-fno-omit-frame-pointer -Wno-unused-variable \
-Wno-attributes                              \
-fno-asynchronous-unwind-tables              \
-ftime-report                                \
-g

LDFLAGS := -lm

OPT ?= 0
CFLAGS += -O$(OPT)

.PHONY: all run clean help
all: clean $(BIN)
$(BIN): $(SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
run: all
	./$(BIN)
clean:
	rm -rf build
