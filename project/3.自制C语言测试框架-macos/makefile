.PHONY: clean run

all: main.o haizei/test.o haizei/test.h
	g++ -I./ main.o haizei/test.o -o ./bin/haizei
main.o: main.cpp haizei/test.h
	g++ -I./ -c main.cpp
haizei/test.o: haizei/test.cc haizei/test.h 
	g++ -I./ -c haizei/test.cc -o haizei/test.o
clean:
	rm -rf bin/haizei main.o haizei/test.o
run:
	./bin/haizei
