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

class Sequence;


class Assembler{
    
public:
    
    bool readGraph(const std::string& filename);
    Sequence assemble();
};



#endif /* defined(__P3_BI1__Assembler__) */
