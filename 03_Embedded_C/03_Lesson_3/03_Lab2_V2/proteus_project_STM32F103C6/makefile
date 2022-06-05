# Prepared by Mohamed Mohsen
CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -gdwarf-2
INCS = -I .
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
OUTPUT_FILE = output

all: $(OUTPUT_FILE).hex 

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(OUTPUT_FILE).elf: $(OBJ) startup.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map

$(OUTPUT_FILE).hex: $(OUTPUT_FILE).elf
	$(CC)objcopy.exe -O binary $< $@ 
	@echo "***************** Build Done *****************"

clean:
	rm -rf *.elf *bin 
	@echo "***************** Clean Done *****************"
clean_all:
	rm -rf *.o *.elf *.bin *.hex *.map
	@echo "***************** Clean Done *****************"