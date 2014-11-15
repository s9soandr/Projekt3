#include <stdio.h>
#include <vector>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Node.h"
#include "Edge.h"
#include <typeinfo>

class NoEdgeException{

};


/*PUBLIC METHODS*/

Node::Node(const Sequence& seq): sequence(seq){
    std::vector<Edge> i;
    std::vector<Edge> o;
    inedges = i;
    outedges = o;
}

Sequence dummy("");
Node::Node(const Node& n): inedges(n.getInEdges()), outedges(n.getOutEdges()), sequence(n.getSequence(dummy)){}

Node::~Node(){};

Node& Node::operator=(const Node& n){
    inedges = n.getInEdges();
    outedges = n.getOutEdges();
    sequence.setSequence(n.getSequence(dummy).getSequence());
    return (*this);
}

//Returns a vector containing all outgoing edges
std::vector<Edge> Node::getOutEdges() const {

    return (*this).outedges;
}

//Returns a vector containing all ingoing edges
std::vector<Edge> Node::getInEdges()const {

    return (*this).inedges;

}

//Builds an edge from this node to the given node with the exact weight of the edge.
//In case the edge is already existing this edge is returned
Edge Node::buildEdgeTo(Node& node){


    //If the edge exists it will be simply returned
    try{
        Edge e(existsOut(node).first);
        return e;
    }
    //If the edge does not exist an exception is thrown which calls the edge constructor to produce a new edge
    //The edge is added to the ingoing and outgoing edges lists
    catch(NoEdgeException ex){
    }

    Sequence dummy("");
    Sequence dummy2("");
    Sequence dummy3("");

    int p = (*this).getSequence(dummy3).overlap(node.getSequence(dummy2), dummy);

    Edge e((*this), node, p, dummy.getSequence());

    if(p > 0){
        addOutgoing(e);
        node.addIngoing(e);
    }

    return e;

}

//In case there is already an edge between this node and the given node, the edge will be removed
void Node::removeEdgeTo(Node& node){

    try{
        int eraseplace = (*this).existsOut(node).second;
        outedges.erase(outedges.begin()+ eraseplace);

        eraseplace = node.existsIn((*this)).second;
        node.inedges.erase(node.inedges.begin() + eraseplace);
    }

    catch(NoEdgeException e){
        return;
    }
}


bool Node::operator==(const Node & node){

    return (*this).sequence == node.sequence;
}

bool Node::operator!=(const Node & node){

    return (*this).sequence == node.sequence;
}


Sequence& Node::getSequence(Sequence& s) const{

    s.setSequence(sequence.getSequence());
    return s;
}


/* HELPER METHODS (private methods)*/

 //Returns the edge if an outgoing edge from this node to the given node exists already, else raise exception
std::pair<Edge&, int> Node::existsOut(Node & n){

    //Iterating through the vector to find the correct edge
    for(unsigned int i=0; i < outedges.size(); i++){

        //If the given node equals an outgoing node, the edge exists
        if(n == outedges.at(i).getTarget()){
            std::pair<Edge &, int> e(outedges.at(i), i);
            return e;
        }
    }

    throw NoEdgeException();
}

//Returns the edge if an ingoing edge from the other node to this node exists already, else raise exception
std::pair<Edge&, int> Node::existsIn(Node & n){

    //Iterating through the vector to find the correct edge
    for(unsigned int i=0; i < inedges.size(); i++){

        //If the given node equals an ingoing node, the edge exists
        if(n == inedges.at(i).getSource()){
            std::pair<Edge &, int> e(inedges.at(i), i);
            return e;
        }
    }

    throw NoEdgeException();
}


//Adds a new Edge to the ingoing edges list (unsorted)
void Node::addIngoing(Edge & e){

    inedges.push_back(e);

}

//Adds a new Edge to the outgoing edges list (sorted)
void Node::addOutgoing(Edge & e){

    std::vector<Edge> newEdges;

    //The given edge is sorted into the list (sorted in descending order)
    for(unsigned int i = 0; i< outedges.size(); i++){

        //The last node that is inserted decides which node might be given back, when looking for the largest overlap
        if(e.getOverlap() >= outedges.at(i).getOverlap() ){

            break;
        }
        else{
            newEdges.push_back(outedges.at(i));
        }

    }

    newEdges.push_back(e);

    for(unsigned int i = newEdges.size() - 1; i < outedges.size(); i++){

        newEdges.push_back(outedges.at(i));
    }

    outedges = newEdges;

}
