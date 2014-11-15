#include <stdio.h>
#include <list>
#include <stdexcept>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"


/*PUBLIC METHODS*/

Graph::Graph(){
	std::list<Node> n;
	nodes = n;
}

Graph::Graph(const std::list<Node> n): nodes(n){}

//Returns true if a node with the given sequence exists
bool Graph::hasNode(const Sequence& seq) const{

    Sequence dummy("");
    //Iterating through the list
    for(std::list<Node>::const_iterator it=nodes.begin(); it != nodes.end(); ++it){

        if((*it).getSequence(dummy) == seq){

            return true;
        }

    }

    return false;

}

//Returns the node with the given sequence
//It builds a node if it is not existing
Node& Graph::getNode(const Sequence& seq){

	Node n(seq);
	
    Sequence dummy("");
    //Iterating through the list
    for(std::list<Node>::iterator i = nodes.begin(); i != nodes.end(); i++){

        if((*i).getSequence(dummy) == seq){

            return (*i);
        }

    }

	insertNode(n);
	
	return n;
}

//Removes the given node and all its dependencies
void Graph::removeNode(Node& node){

    //From those two lists the node has to be deleted
    std::vector<Edge> out(node.getOutEdges());
    std::vector<Edge> in(node.getInEdges());

    Sequence dummy("");
    //Iterate through the outgoing edges list
    for(unsigned int i = 0; i< out.size(); i++){

        Node &I_dont_want_const = getNode(out.at(i).getTarget().getSequence(dummy));
        //Remove the edges from node to the it's target node
        (node).removeEdgeTo(I_dont_want_const);
    }

    //Iterate through the incoming edges list
    for(unsigned int i = 0; i< in.size(); i++){

        Node I_still_dont_want_const = getNode(out.at(i).getSource().getSequence(dummy));
        //Remove the edges from the source node to node
        I_still_dont_want_const.removeEdgeTo(node);

    }

    //Remove the node from the node's list
    nodes.remove(node);

}

//Returns the edge from source to target
Edge Graph::getEdge(Node& src, Node& target){

    Sequence dummy("");
    //Builds the two nodes if they are not yet existing
    getNode(src.getSequence(dummy));
    getNode(target.getSequence(dummy));

    std::vector<Edge> out = src.getOutEdges();

    //Iterate through the outgoing edges and try to find the correct edge
    for(unsigned int i=0; i < out.size(); i++){

        if(out.at(i).getTarget().getSequence(dummy) == target.getSequence(dummy)){

            return out.at(i);
        }
    }

    //If there is no correct edge, create it
    return src.buildEdgeTo(target);
}

//Identifies the nodes which belong to the two sources and connects them with getEdge(node,node)
Edge Graph::getEdge(const Sequence& src, const Sequence& target){

    Node source = getNode(src);
    Node t = getNode(target);

    return getEdge(source, t);
}

//Returns the graph as .dot file
std::ostream& operator << (std::ostream& strm, const Graph& graph){
	
	strm << "digraph GraphvizDarstellung{\n" ;
	strm << "nodesep = 2\n";
	
    Sequence dummy("");
    //Iterating through the nodes list
    for(std::list<Node>::const_iterator it = graph.nodes.begin(); it != graph.nodes.end(); it++){
		
		for(unsigned int i = 0 ; i< (*it).getOutEdges().size(); i++){
			
			
			strm << (*it).getSequence(dummy).getSequence();
			strm << " -> " ;
			strm << (*it).getOutEdges().at(i).getTarget().getSequence(dummy).getSequence();
			strm <<  " [label =  ";
			strm << "\"";
			strm << (*it).getOutEdges().at(i).getOverlap() ;
			strm << " , ";
			strm << (*it).getOutEdges().at(i).getOverlapSeq();
			strm << "\" ] \n";
        
		}
    }

	strm << "}\n";
    return strm;
}

//Converts the graph from the graphviz format to our graph format
std::istream& operator >> (std::istream& strm, Graph& graph){

    if (!strm){

        throw std::invalid_argument("Stream was not opened");
    }

    std::string puffer;

    while(getline(strm, puffer)){

        graph.getNode(puffer);
    }

    return strm;
}

std::list<Node> Graph::getNodes(){
	
	return nodes;
}

std::list<Edge> Graph::getEdges(){
    std::list<Edge> edges;
    
    // fuer alle Knoten
    for(std::list<Node>::iterator i = nodes.begin(); i != nodes.end(); i++){
        std::vector<Edge> outedges_i = (*i).getOutEdges();
        
        // fuer alle Kanten
        for (std::vector<Edge>::iterator j=outedges_i.begin(); j != outedges_i.end(); j++) {
            edges.push_back((*j));
        }
        
    }
    
    return edges;
}


/*HELPER METHODS (PRIVATE METHODS)*/

//This methods adds a node to the graph it simultaneously already builds the edges
Node& Graph::insertNode(Node& n){

    for(std::list<Node>::iterator i = nodes.begin(); i != nodes.end(); i++){
		
        n.buildEdgeTo((*i));
        (*i).buildEdgeTo(n);
    }

    nodes.push_back(n);

    return n;
}
