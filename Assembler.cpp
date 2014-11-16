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

// Constructor
Assembler::Assembler(){
    std::vector<Sequence> fragmente;
    F=fragmente;
}

// Destructor
Assembler::~Assembler(){
    
}



// returns the given Fragments as Sequences
std::vector<Sequence> Assembler::getFragments(){
    return F;
}

// reads Overlap Graph, returns if Graph is correct
bool readGraph(const std::string& filename){
    // Graph
    std::list<Node> nodes;
    Graph fragGraph(nodes);
    
    //
    std::ifstream fragments;
    fragments.open(filename, std::ifstream::in);
    
    // checks, if file was correct opened
    if(!fragments){
        return false;
    }
    else{
        fragments >> fragGraph;
        fragments.close();
        return true;
    }
}

// join Nodes until you have the assembled Sequence
Sequence assemble(){
    Sequence dummy("");
    return dummy;
}