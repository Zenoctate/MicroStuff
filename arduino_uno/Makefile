BINFILE = out.bin

MICROCONTROLLER = atmega328p
PORT = /dev/ttyACM0		# Probably won't change unless many Arduinos are connected

CC = avr-gcc
CFLAGS = -mmcu=$(MICROCONTROLLER) -DF_CPU=16000000UL -Wall -nostdlib -nodefaultlibs -nostartfiles

OBJCOPY = avr-objcopy
OBJFLAGS = -O binary -R .eeprom

FLASHER = avrdude
FLASHFLAGS = -p $(MICROCONTROLLER) -c arduino -P $(PORT) -b 115200

CSRC = $(shell find . -name "*.c")
HSRC = $(shell find . -name "*.h")

flash: $(CSRC) $(HSRC)
	$(CC) $(CFLAGS) -o intermediate.elf $(CSRC)
	$(OBJCOPY) $(OBJFLAGS) intermediate.elf $(BINFILE)
	$(FLASHER) $(FLASHFLAGS) -U flash:w:$(BINFILE):r

check:
	avrdude -p $(MICROCONTROLLER) -c arduino -P $(PORT) -b 115200 -v

clean:
	rm -rf *.elf *.bin
