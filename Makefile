CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -Isrc
BUILD_DIR = build
SRC_DIR = src

# Trova tutti i .c sotto src/
SRCS = $(shell find $(SRC_DIR) -name '*.c')

# Crea i relativi .o in build/ mantenendo la gerarchia
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Target finale
TARGET = $(BUILD_DIR)/main

# Regola di default
all: $(TARGET)

# Regola per costruire l'eseguibile
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regola per compilare ogni .c in .o mantenendo struttura
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
