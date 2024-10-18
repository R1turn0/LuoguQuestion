# Notation: Use make -k. :)

.PHONY: all clean

PWD := $(shell pwd)
DIR_TARGET := $(PWD)/bin/
DIR_SRC := $(PWD)/src/

BIN_FILE := mov lea add sub push pop
TARGET := $(foreach n, $(BIN_FILE), $(DIR_TARGET)$(n))

CC := gcc
CFLAGS := -g

all: $(TARGET)

$(TARGET): $(DIR_TARGET)%: $(DIR_SRC)ins_%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@-rm $(DIR_TARGET)*