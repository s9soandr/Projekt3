#include <stdio.h>
#include <vector>
#include "Sequence.h"
#include <utility>

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Edge;
class Sequence;

class Node{

private:
    std::vector<Edge> inedges;
    std::vector<Edge> outedges;
    Sequence sequence;
    //Returns the edge if an outgoing edge from this node to the given node exists already, else raise exception
    std::pair<Edge&, int> existsOut(Node & e);
    //Returns the edge if an ingoing edge from the other node to this node exists already, else raise exception
    std::pair<Edge&, int> existsIn(Node & e);
    //Adds a new Edge to the ingoing edges list (unsorted)
    void addIngoing(Edge & e);
    //Adds a new Edge to the outgoing edges list (sorted)
    void addOutgoing(Edge & e);


public:

    explicit Node(const Sequence& sequence);
    Node(const Node& n);
    ~Node();

    //Returns a vector containing all outgoing edges
    std::vector<Edge> getOutEdges() const;

    //Returns a vector containing all ingoing edges
    std::vector<Edge> getInEdges()const;

    //Builds an edge from this node to the given node with the exact weight of the edge.
    //In case the edge is already existing this edge is returned
    Edge buildEdgeTo(Node& node);

    //In case there is already an edge between this node and the given node, the edge will be removed
    void removeEdgeTo(Node& node);

    //Assigning/ Equality/ Inequality operator
    Node& operator=(const Node & node);
    bool operator==(const Node & node);
    bool operator!=(const Node & node);

    Sequence& getSequence(Sequence& s) const;
};


#endif // NODE_H_INCLUDED
