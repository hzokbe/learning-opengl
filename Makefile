CC := gcc

CFLAGS := -std=c2x -Wall -Wextra -Werror -Wpedantic -Wno-unused-parameter -Iinclude

LDFLAGS := -lGL -lglfw -lGLEW -lm

SRC_DIR := src

OUT_DIR := out

BUILD_DIR := build

TARGET := $(OUT_DIR)/main

SRCS := $(wildcard $(SRC_DIR)/*.c)

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

$(TARGET): $(OBJS) | $(OUT_DIR)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR) $(BUILD_DIR):
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OUT_DIR) $(BUILD_DIR)

.PHONY: run clean
