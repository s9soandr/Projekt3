#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdexcept>
#include "Graph.h"
#include "Edge.h"
#include "Node.h"
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Assembler.h"

using namespace std;

int main()
{
    Sequence dummy("");
    //Tests the nodes
    //Constructor and getter
    DNA dna("TTAAGGAATT");
    Node n(dna);
    assert(n.getSequence(dummy).getSequence() == dna.getSequence());

    //Copyconstuctor and == operator
    Node m(n);
    assert(n.getSequence(dummy) == m.getSequence(dummy) &&
           (n.getSequence(dummy).getSequence() == m.getSequence(dummy).getSequence()));

    //= operator
    DNA dna2("GGTTAATGT");
    Node test(dna2);
    assert(!(n == test));
    test = n;
    assert(n == test);
    Node o(dna2);

    //Tests the edges
    //Constructor and getter
    Edge e(o, n, 1, "T");
    assert(o == e.getSource());
    assert(n == e.getTarget());
    assert(1 == e.getOverlap());
    assert("T" == e.getOverlapSeq());

    //Copyconstructor and == operator
    Edge f(e);
    assert(f == e);

    //= operator
    Edge g(n, o, 0, "");
    assert(!(g == e));
    g = e;
    assert(g == e);

    //Node::buildEdgeTo
    o.buildEdgeTo(n);
    assert(*(o.getOutEdges().begin()) == e);
    assert(*(n.getInEdges().begin()) == e);
    
    //Node::removeEdgeTo
    o.removeEdgeTo(n);
    assert(o.getOutEdges().size() == 0);
    assert(n.getInEdges().size() == 0);
    
    //Testing Graph
    std::list<Node> nodes;
    Graph graph(nodes);
    
    graph.getNode(o.getSequence(dummy));
    assert(graph.getNodes().size() == 1);
    assert(graph.getNode(o.getSequence(dummy)) == o);
    
    graph.getNode(n.getSequence(dummy));
    assert(graph.getNodes().size() == 2);
    assert(graph.getNode(n.getSequence(dummy)) == n);
    
    Node o2 = graph.getNode(o.getSequence(dummy));
    Node n2 = graph.getNode(n.getSequence(dummy));
    
    assert(*(o2.getOutEdges().begin()) == e);
    assert(*(n2.getInEdges().begin()) == e);
    assert(o2.getOutEdges().size() == 1);
    assert(o2.getInEdges().size() == 0);
    assert(n2.getOutEdges().size() == 0);
    assert(n2.getInEdges().size() == 1);
    
    //Graph::hasNode()
    assert(graph.hasNode(o2.getSequence(dummy)));
    assert(graph.hasNode(n2.getSequence(dummy)));
    Sequence sequence("TTAAGG");
    Node negative(sequence);
    assert(!graph.hasNode(negative.getSequence(dummy)));
    
    //Graph::getEdge()
    assert(graph.getEdge(o2, n2) == e);
    Edge e2(n2, o2, 0, "");
    assert(graph.getEdge(n2, o2) == e2);
    assert(o2.getOutEdges().size() == 1);
    assert(o2.getInEdges().size() == 0);
    assert(n2.getOutEdges().size() == 0);
    assert(n2.getInEdges().size() == 1);
    
    //Graph::removeNode()
    graph.removeNode(o2);
    assert(graph.getNodes().size() == 1);
    assert(!graph.hasNode(o2.getSequence(dummy)));
    assert(o2.getOutEdges().size() == 0);
    assert(o2.getInEdges().size() == 0);
    
    Node n3 = graph.getNode(n2.getSequence(dummy));
    assert(n3.getOutEdges().size() == 0);
    assert(n3.getInEdges().size() == 0);
    
    //Graph in and output
    std::list<Node> nodes2;
    Graph fragGraph(nodes2);
	
	ifstream fragments;
	fragments.open("fragments.fta", std::ifstream::in);
	
	/*if(!fragments){
		throw std::invalid_argument("fragments.fta wurde nicht geöffnet");
	}
	
	fragments >> fragGraph;
	
	std::cout << fragGraph;
	
	fragments.close();*/
    
    // Assembler
    Graph testGraph(std::list<Node>);
    //Assembler(testGraph);

    return 0;
}
