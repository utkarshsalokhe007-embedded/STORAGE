TARGET = firmware

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

CPU = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard

CFLAGS = $(CPU) -Wall -O0 -g -std=c11 -ffunction-sections -fdata-sections -Iinc
LDFLAGS = $(CPU) -nostdlib -T linker.ld -Wl,--gc-sections -Wl,-Map=$(TARGET).map

SRCS = src/main.c
ASM_SRCS = startup_stm32f407xx.s

OBJS = $(SRCS:.c=.o) $(ASM_SRCS:.s=.o)

all: $(TARGET).elf $(TARGET).bin $(TARGET).hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CPU) -c $< -o $@

$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
	$(SIZE) $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

clean:
	rm -f src/*.o *.o $(TARGET).elf $(TARGET).bin $(TARGET).hex $(TARGET).map

.PHONY: all clean
