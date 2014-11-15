#include <stdio.h>
#include "Node.h"
#include "Edge.h"
#include <utility>


Edge::Edge(Node& s, Node& t, unsigned int o, std::string seq): source(s), target(t), overlap(o), overlap_seq(seq) {}

Edge::Edge(const Edge& e): source(e.source), target(e.target), overlap(e.overlap), overlap_seq(e.overlap_seq) {}

Edge::~Edge(){}

Edge& Edge::operator=(const Edge& e){

    source = e.source;
    target = e.target;
    overlap = e.overlap;
    overlap_seq = e.overlap_seq;

    return (*this);
}

//Gives back the node where the edge comes from
const Node& Edge::getSource() const{

    return source;

}

//Gives back the node where the edge goes to
const Node& Edge::getTarget() const{

    return target;
}

//Returns the overlap of the two nodes
unsigned int Edge::getOverlap() const{

    return overlap;

}

//Returns the overlap's string representation
std::string Edge::getOverlapSeq() const{

    return overlap_seq;

}

bool Edge::operator==(const Edge& e){

    return (source == e.source) && (target == e.target)
        && (overlap == e.overlap) && (overlap_seq == e.overlap_seq);

}

bool Edge::operator!=(const Edge& e){
	
	return (source != e.source) && (target != e.target)
		&& (overlap != e.overlap) && (overlap_seq == e.overlap_seq);
}



