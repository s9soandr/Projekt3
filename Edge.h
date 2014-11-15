#include <stdio.h>
#include "Node.h"
#include <string>

#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

class Node;

class Edge{

private:
    Node source;
    Node target;
    unsigned int overlap;
    std::string overlap_seq;
    
    
public:

    Edge(Node& source, Node& target, unsigned int o, std::string seq);
    Edge(const Edge& e);
    ~Edge();
    Edge& operator=(const Edge& e);

    //Gives back the node where the edge comes from
    const Node& getSource() const;

    //Gives back the node where the edge goes to
    const Node& getTarget() const;

    //Returns the overlap of the two nodes
    unsigned int getOverlap() const;

    //Returns the overlap's string representation
    std::string getOverlapSeq() const;

    bool operator==(const Edge& e);
    
    bool operator!=(const Edge& e);


};

#endif // EDGE_H_INCLUDED
