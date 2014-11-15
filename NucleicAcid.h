#include <iostream>
#include <string>
#include "Sequence.h"


#ifndef NUCLEICACID_H_INCLUDED
#define NUCLEICACID_H_INCLUDED


class NucleicAcid: public Sequence {

public:
    NucleicAcid();
    NucleicAcid(std::string str);
    NucleicAcid(NucleicAcid & na);
    ~NucleicAcid();
    NucleicAcid& operator=(const NucleicAcid & seq);
    friend std::istream& operator>>(std::istream& st, NucleicAcid& seq);
    friend std::ostream& operator<<(std::ostream& st, NucleicAcid& seq);

};

#endif // NUCLEICACID_H_INCLUDED
