TARGET := GSpad-DS4modle-auto-reconnect.elf
SRCS := src/main.c src/hid_parser.c src/virtual_ds4.c src/popup_account.c
OBJS := $(SRCS:.c=.o)

ifndef PS5_PAYLOAD_SDK
$(error PS5_PAYLOAD_SDK is not set)
endif

include $(PS5_PAYLOAD_SDK)/toolchain/prospero.mk

CFLAGS += -O2 -Wall -Wextra -Isrc
LDFLAGS += -nostdlib

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $@

clean:
	rm -f $(OBJS) $(TARGET)
