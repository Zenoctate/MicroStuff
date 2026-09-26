BINFILE = out.bin

MICROCONTROLLER = atmega328p
PORT = /dev/ttyACM0		# Probably won't change unless many Arduinos are connected

SRC_DIR = src
CSRC = $(shell find $(SRC_DIR) -name "*.c")
ASRC = $(shell find $(SRC_DIR) -name "*.S")
INC_DIR = include
HSRC = $(shell find $(INC_DIR) -name "*.h")

CC = avr-gcc
CFLAGS = -mmcu=$(MICROCONTROLLER) -Wall -nostdlib -nodefaultlibs -nostartfiles \
	-Wno-builtin-declaration-mismatch

OBJCOPY = avr-objcopy
OBJFLAGS = -O binary -R .eeprom

FLASHER = avrdude
FLASHFLAGS = -p $(MICROCONTROLLER) -c arduino -P $(PORT) -b 115200

all: compile flash

compile: $(CSRC) $(HSRC) $(ASRC)
	$(CC) $(CFLAGS) -o intermediate.elf $(CSRC) $(ASRC) -I$(INC_DIR)
	$(OBJCOPY) $(OBJFLAGS) intermediate.elf $(BINFILE)

flash: compile
	$(FLASHER) $(FLASHFLAGS) -U flash:w:$(BINFILE):r

check:
	avrdude -p $(MICROCONTROLLER) -c arduino -P $(PORT) -b 115200 -v

clean:
	rm -rf *.elf *.bin
