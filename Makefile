all: key.o node.o heap.o main

heap.o: node.o key.o
	g++ Heap.cpp -c

node.o: key.o
	g++ Node.cpp -c

key.o:
	g++ Key.cpp -c

main: node.o key.o heap.o
	g++ main.cpp Node.o Key.o Heap.o -lm -o ex

clean:
	rm -rf *.o
