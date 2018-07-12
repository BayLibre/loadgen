#CC = gcc
CC = ~/gcc-linaro-5.3.1-2016.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc
CFLAGS = -march=armv8-a -mtune=cortex-a57.cortex-a53 --static

CFLAGS += -O2 -DMULTITHREAD=64

OBJ = main.o crc32.o md5.o nqueens.o blowfish.o dhrystone.o dhry_21b.o linpack.o syscalls.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

loadgen: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lpthread

clean:
	rm -f *.o loadgen
