//
//  Assembler.cpp
//  P3_BI1
//
//  Created by Solveig Andres on 16.11.14.
//  Copyright (c) 2014 Solveig Andres, Eva Maria Paul. All rights reserved.
//

#include "Assembler.h"
#include "Sequence.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "Graph.h"
#include "Node.h"

// Constructor
Assembler::Assembler(Graph& mygraph):graph(mygraph){
     std::vector<Sequence> fragmente;
     F=fragmente;
    
}

// Destructor
Assembler::~Assembler(){
    
}





// reads Overlap Graph, returns if Graph is correct
bool Assembler::readGraph(const std::string& filename){
    
    /*std::ifstream fragments;
    fragments.open(filename, std::ifstream::in);
    
    // checks, if file was correct opened
    if(!fragments){
        return false;
    }
    else{
        fragments >> graph;
        fragments.close();
        return true;
    }*/
    return true;
}

// reversiert und komplementiert eine Sequence, gibt neues Objekt zurueck
Sequence& Assembler::reverse_com(Sequence& seq,Sequence& rev_comp_seq){
    rev_comp_seq=seq;
    rev_comp_seq.reverseSeq();
    rev_comp_seq.complementSeq();
    return rev_comp_seq;
}

// returns |Overlap(A,B)|
unsigned int Assembler::getWeight(Sequence& seq_A, Sequence& seq_B){
    // create Edge form Sequence A to B
    Node source_node(seq_A);
    Node target_node(seq_B);

    Edge edge=source_node.buildEdgeTo(target_node);
    // return overlap
    return edge.getOverlap();
}

// berechnet same
unsigned int Assembler::same(Sequence& seq_A, Sequence& seq_B){
    unsigned int w_A_B = getWeight(seq_A, seq_B); // Gewicht der Kante A -> B
    unsigned int w_B_A = getWeight(seq_B, seq_A); // Gewicht der Kante B -> A
    // finde Maximum
    if (w_A_B>w_B_A) {
        return w_A_B;
    }
    else{
        return w_B_A;
    }

}
// berechnet opp
unsigned int Assembler::opp(Sequence& seq_A, Sequence& rev_seq_B){
    
    unsigned int w_A_cB = getWeight(seq_A, rev_seq_B); // Gewicht der Kante A -> cB
    unsigned int w_cB_A = getWeight(rev_seq_B, seq_A); // Gewicht der Kante cB -> A
    // finde Maximum
    if (w_A_cB>w_cB_A) {
        return w_A_cB;
    }
    else{
        return w_cB_A;
    }

    
}

// berechnet die Summe same
unsigned int Assembler::w_fi(Sequence& fi, std::vector<Sequence>& f){
    // initialisiere Summe mit 0
    unsigned int sum=0;
    // berechne die Summe von same
    for (std::vector<Sequence>::iterator it=f.begin(); it!=f.end();it++){
        sum=sum+same(fi, (*it));
    }
    return sum;
}

unsigned int Assembler::w_cfi(Sequence& cfi, std::vector<Sequence>& f){
    // initialisiere Summe mit 0
    unsigned int sum=0;
    // berechne die Summe von same
    for (std::vector<Sequence>::iterator it=f.begin(); it!=f.end();it++){
        sum=sum+opp(cfi, (*it));
    }
    return sum;
}



std::vector<Sequence> Assembler::Greedy(std::vector<Sequence>& fragments){
    // leere Menge der Orientation
    std::vector<Sequence> orientation;
    
    // Anzahl der Elemente
    unsigned long anz_der_fragmente = fragments.size();
    
    // keine Fragmente vorhanden
    if (anz_der_fragmente==0) {
        return orientation;
    }
    else{
        for (std::vector<Sequence>::iterator it=F.begin(); it!=F.end();it++) {
            // fuege zu Beginn erstes Element  hinzu
            if (std::distance(F.begin(), it)==0) {
                orientation.push_back(*it); // fuege f_1 hinzu
            }
            else{
                Sequence seq=(*it); // Sequence
                Sequence dummy_seq;
                Sequence rev_seq=reverse_com(*it,dummy_seq); // reversierte komplementaere Sequence
                // vergleiche Gewichtssummen und fuege Maximum zu Orientation
                if (w_fi(seq, orientation)>w_cfi(rev_seq, orientation)) {
                    orientation.push_back(seq);
                }
                else{
                    orientation.push_back(rev_seq);
                }
                
            }
        }
    }
    
    return orientation ;
    
}

// join Nodes until you have the assembled Sequence
Sequence Assembler::assemble(){
    Sequence assembled_seq;
    graph.sortEdges();
    while (graph.getSortedEdges().size()>1) {
        // sortiere erst die Kanten der groesse nach
        graph.sortEdges();
        // nimm die Kante mit dem groessten Gewicht
        Edge first_edge=graph.getSortedEdges().front();
        // verbinde die Kante mit dem groessten Gewicht
        graph.joinNodes(first_edge);
    }
    assembled_seq = graph.getNodes().front().getStringSequence(); // hole die Sequence letzten Knoten
    return assembled_seq;
}

