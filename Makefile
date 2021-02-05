all: program

program:
	g++ -o program pointers.cpp

clean:
	rm program