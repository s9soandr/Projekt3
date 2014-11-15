//
//  CompEdge.cpp
//  Projekt_3_BI1
//
//  Created by Solveig Andres on 15.11.14.
//  Copyright (c) 2014 Solveig Andres, Eva Maria Paul. All rights reserved.
//

#include "Edge.h"

class CompEdge{
    
public:
    // if Edge Weight e1 > e2 then return true, else false
    bool operator()(const Edge& e1 , const Edge e2){
        return (e1.getOverlap()>e2.getOverlap());
    }
};
