CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m4 -gdwarf-2 -g
INCS = -I .
LIBS = 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
PROJECT_NAME = lab4_arm_cortexm4


all: $(PROJECT_NAME).bin

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map
	cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf


$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@ 
	@echo "======================= Build Done ======================="

clean:
	rm *.elf *.bin
	@echo "======================= Clean Done ======================="
clean_all:
	rm *.o *.elf *.bin
	@echo "======================= Clean Done ======================="