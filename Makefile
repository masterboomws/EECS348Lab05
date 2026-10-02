CC=g++

prog: main.cpp
	$(CC) main.cpp -o main

run: main
	./main

clean:
	rm -rf *.o prog
