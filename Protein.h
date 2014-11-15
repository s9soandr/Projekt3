#include <iostream>
#include <string>
#include "Sequence.h"

#ifndef PROTEIN_H_INCLUDED
#define PROTEIN_H_INCLUDED


class Protein: public Sequence {

public:
    Protein();
    Protein(std::string str);
    Protein(Protein & na);
    ~Protein();
    Protein& operator=(const Protein & seq);
    friend std::istream& operator>>(std::istream& st, Protein& seq);
    friend std::ostream& operator<<(std::ostream& st, Protein& seq);
    virtual bool isValid() const ;

};


#endif // PROTEIN_H_INCLUDED
