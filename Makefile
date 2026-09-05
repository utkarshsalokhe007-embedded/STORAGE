TARGET = firmware

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

# -mcpu=cortex-m4         : target core
# -mthumb                 : Thumb instruction set (Cortex-M only supports this)
# -mfpu=fpv4-sp-d16       : F407 has a single-precision hardware FPU
# -mfloat-abi=hard        : use hardware FPU registers for float args/returns
#                           (must match across ALL object files, or you'll
#                           get calling-convention mismatches / hard faults)
CPU = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard

# -O0 -g        : no optimization, debug symbols (good while learning/debugging)
# -ffunction-sections -fdata-sections : puts each function/variable in its
#                 own section so the linker's --gc-sections can strip unused ones
CFLAGS = $(CPU) -Wall -O0 -g -std=c11 -ffunction-sections -fdata-sections
CFLAGS += -Idriver_header

# -nostdlib      : no standard library / no C runtime startup (we provide our own)
# -T linker.ld   : use our memory layout
# --gc-sections  : discard unused functions/data (keeps binary small)
# -Map=...       : generates a .map file - useful for seeing where symbols ended up
LDFLAGS = $(CPU) -nostdlib -T linker.ld -Wl,--gc-sections -Wl,-Map=$(TARGET).map

SRCS = src/main.c $(wildcard driver_src/*.c)
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
	rm -f src/*.o driver_src/*.o *.o $(TARGET).elf $(TARGET).bin $(TARGET).hex $(TARGET).map

.PHONY: all clean