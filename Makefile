vertex.o:
	g++ -c Vertex.cpp

edge.o: Vertex.h
	g++ -c Edge.cpp

unionfind.o:
	g++ -c UnionFind.cpp

node.o:
	g++ -c Node.cpp

heap.o: Node.h
	g++ -c Heap.cpp

graph.o: Vertex.h UnionFind.h Heap.h
	g++ -c Graph.cpp

main.o:
	g++ -c main.cpp

exe:
	g++ -o Vertex.o Edge.o UnionFind.o Node.o Heap.o Graph.o main.cpp 

ex: vertex.o edge.o unionfind.o node.o heap.o graph.o main.o
#	g++ -o ex main.cpp
#	g++ -o ex Vertex.o Edge.o UnionFind.o Node.o Heap.o Graph.o main.o
	g++ -o ex Vertex.cpp Edge.cpp UnionFind.cpp Node.cpp Heap.cpp Graph.cpp main.cpp
