//
//  Assembler.h
//  P3_BI1
//
//  Created by Solveig Andres on 16.11.14.
//  Copyright (c) 2014 Solveig Andres, Eva Maria Paul. All rights reserved.
//

#ifndef __P3_BI1__Assembler__
#define __P3_BI1__Assembler__

#include <stdio.h>
#include <string>
#include <vector>
#include <list>

class Sequence;
class Node;
class Graph;
class Assembler{
    
private:
    std::vector<Sequence> F; // Fragmentmenge F
    std::vector<Sequence> O;
    Graph& graph; // Graph

public:

    // Constructor
    Assembler(Graph& mygraph);
    
    // Destructor
    ~Assembler();
    
    // reads Overlap Graph, returns if Graph is correct
    bool readGraph(const std::string& filename);
    
    // join Nodes until you have the assembled Sequence
    Sequence assemble();
    
    // Greedy - Algorithm
    std::vector<Sequence> Greedy(std::vector<Sequence>& F);
    
    // Meine Methoden -------------------------------------
    
    // returns |Overlap(A,B)|
    unsigned int getWeight(Sequence& seq_A, Sequence& seq_B);
    
    // berechnet same
    unsigned int same(Sequence& seq_A, Sequence& seq_B);
    
    // berechnet die Summe same
    unsigned int w_fi(Sequence& fi, std::vector<Sequence>& f);
    
    // berechnet opp
    unsigned int opp(Sequence& seq_A, Sequence& seq_B);
    
    // berechnet die Summe opp
    unsigned int w_cfi(Sequence& cfi, std::vector<Sequence>& f);
    
    
    // revesiert komplementiert
    Sequence& reverse_com(Sequence& seq,Sequence& rev_comp_seq);
    
   
   


};



#endif /* defined(__P3_BI1__Assembler__) */
