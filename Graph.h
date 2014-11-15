#include <stdio.h>
#include <list>


#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

class Node;
class Edge;
class Sequence;


class Graph{
private:
    std::list<Node> nodes;
    //This methods adds a node to the graph it simultaneously already builds the edges
    Node& insertNode(Node &n);
    std::list<Edge> sorted_edges; // wird bei aufruf von sortEdges() gesetzt

    //CompEdge comperator;
public:

	Graph();
	
	Graph(const std::list<Node> n);

    //Returns true if a node with the given sequence exists
    bool hasNode(const Sequence& seq) const;

    //Returns the node with the given sequence
    //It builds a node if it is not existing
    Node& getNode(const Sequence& seq);

    //Removes the given node
    void removeNode(Node& node);

    //Returns the edge from source to target
    Edge getEdge(Node& src, Node& target);

    //Not yet decided
    Edge getEdge(const Sequence& src, const Sequence& target);

    //Returns the graph as graphviz format
    friend std::ostream& operator << (std::ostream& strm, const Graph& graph);

    //Converts the graph from the graphviz format to our graph format
    friend std::istream& operator >> (std::istream& strm, Graph& graph);
    
    std::list<Node> getNodes();
    
    // gibt alle Edges zurueck
    std::list<Edge> getEdges();

    // sortiert Kanten nach Kantengewicht von gross nach klein
    void sortEdges();


};

#endif // GRAPH_H_INCLUDED