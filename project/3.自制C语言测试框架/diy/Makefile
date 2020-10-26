.PHONY: clean run

all: output/main.o output/test.o 
	gcc output/main.o output/test.o -o bin/test  
output/main.o: main.c include/test.h 
	gcc -I./ -c main.c -o output/main.o 
output/test.o: src/test.c  
	gcc -I./ -c src/test.c -o output/test.o 

clean:
	rm -rf output/*.o 

run:
	./bin/test

