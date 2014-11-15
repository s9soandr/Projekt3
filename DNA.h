#include <iostream>
#include <string>
#include "Sequence.h"
#include "NucleicAcid.h"

#ifndef DNA_H_INCLUDED
#define DNA_H_INCLUDED


class DNA: public NucleicAcid {

public:
    DNA();
    DNA(std::string);
    DNA(DNA & na);
    ~DNA();
    DNA& operator=(const DNA & seq);
    friend std::istream& operator>>(std::istream& st, DNA& seq);
    friend std::ostream& operator<<(std::ostream& st, DNA& seq);
    virtual bool isValid() const ;

};


#endif // DNA_H_INCLUDED
