# Prepared by Mohamed Mohsen
CC = arm-none-eabi-
CFLAGS = -mcpu=arm926ej-s -g
INCS = -I .
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

all: app.bin 

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

app.elf: $(OBJ) startup.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map

app.bin: app.elf
	$(CC)objcopy.exe -O binary $< $@ 
	@echo "***************** Build Done *****************"

clean:
	rm -rf *.elf *bin 
	@echo "***************** Clean Done *****************"
clean_all:
	rm -rf *.o *.elf *.bin
	@echo "***************** Clean Done *****************"