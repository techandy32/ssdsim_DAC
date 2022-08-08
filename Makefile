# ssdsim linux support
all:ssd 
	
clean:
	rm -f ssd *.o *~
.PHONY: clean

ssd: ssd.o avlTree.o flash.o initialize.o pagemap.o DAC.o 
	cc -g -o ssd ssd.o avlTree.o flash.o initialize.o pagemap.o DAC.o
ssd.o: flash.h initialize.h pagemap.h
	gcc -c -g ssd.c
flash.o: pagemap.h
	gcc -c -g flash.c
initialize.o: avlTree.h pagemap.h
	gcc -c -g initialize.c
pagemap.o: initialize.h DAC.h
	gcc -c -g pagemap.c
avlTree.o: 
	gcc -c -g avlTree.c
DAC.o: DAC.h
	gcc -c -g DAC.c

