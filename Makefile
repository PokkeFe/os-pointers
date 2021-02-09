all: pointers

pointers:
	g++ -o pointers pointers.cpp

clean:
	rm -Rf tests/my_out
	rm pointers

test: pointers
	mkdir tests/my_out
	./pointers < tests/input/in01.txt | head -n 50 > tests/my_out/out01.txt
	./pointers < tests/input/in02.txt | head -n 50 > tests/my_out/out02.txt