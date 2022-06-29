# Prepared by Mohamed Mohsen
CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -gdwarf-2
LIBS = 
INCS = -I .
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
PROJECT_NAME = PDC

all: $(PROJECT_NAME).hex
	@echo "***************** Build Done *****************"

$(PROJECT_NAME).hex: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@

$(PROJECT_NAME).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIB) $(OBJ) $(AsOBJ) -o $@ -Map=mapfile.map

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@


clean:
	rm -rf *.elf *.bin *.hex *.map
	@echo "***************** Clean Done *****************"
clean_all:
	rm -rf *.elf *.bin *.hex *.map *.o
	@echo "***************** Clean Done *****************"