all: Uebung3

Uebung2: main.o Graph.o Edge.o Node.o Sequence.o DNA.o NucleicAcid.o RNA.o Protein.o CompEdge.o
	g++ main.o Graph.o Edge.o Node.o Sequence.o DNA.o NucleicAcid.o RNA.o Protein.o CompEdge.o -o Uebung3

main.o: main.cpp
	g++ -c main.cpp

Graph.o: Graph.cpp
	g++ -c Graph.cpp

Edge.o: Edge.cpp
	g++ -c Edge.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

Sequence.o: Sequence.cpp
	g++ -c Sequence.cpp

NucleicAcid.o: NucleicAcid.cpp
	g++ -c NucleicAcid.cpp

DNA.o:  DNA.cpp 
	g++ -c DNA.cpp

RNA.o: RNA.cpp
	g++ -c RNA.cpp

Protein.o: Protein.cpp
	g++ -c Protein.cpp

CompEdge.o: CompEdge.cpp
	g++ -c CompEdge.cpp

clean:
	rm -rf *.o  Uebung2