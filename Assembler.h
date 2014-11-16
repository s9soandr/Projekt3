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

class Sequence;


class Assembler{
    
private:
    std::vector<Sequence> F; // Fragmentmenge F
    
public:
    
    // Constructor
    Assembler();
    
    //read in the Fragments in string format
    void readIn(const std::string& filename);
    
    //returns the given Fragments as Sequences
    std::vector<Sequence> getFragments();
    
    
    // Destructor
    ~Assembler();
    
    // reads Overlap Graph, returns if Graph is correct
    bool readGraph(const std::string& filename);
    
    // join Nodes until you have the assembled Sequence
    Sequence assemble();
    
    
};



#endif /* defined(__P3_BI1__Assembler__) */
