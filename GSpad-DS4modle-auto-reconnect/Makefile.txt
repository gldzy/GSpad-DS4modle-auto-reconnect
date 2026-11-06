TARGET := GSpad-DS4modle-auto-reconnect.elf
SRCS := src/main.c src/hid_parser.c src/virtual_ds4.c src/popup_account.c
OBJS := $(SRCS:.c=.o)

PS5SDK ?= $(PS5SDK_PATH)
CC := $(PS5SDK)/bin/ps5-gcc
LD := $(PS5SDK)/bin/ps5-ld
CFLAGS := -ffreestanding -march=znver2 -O2 -Wall -Wextra -I$(PS5SDK)/include -Isrc
LDFLAGS := -nostdlib -T $(PS5SDK)/ldscripts/elf.ld

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS) $(TARGET)
