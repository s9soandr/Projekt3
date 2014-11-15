#include <iostream>
#include <string>
#include "Sequence.h"

#ifndef RNA_H_INCLUDED
#define RNA_H_INCLUDED

class RNA: public NucleicAcid {

public:
    RNA();
    RNA(std::string str);
    RNA(RNA & na);
    ~RNA();
    RNA& operator=(const RNA & seq);
    friend std::istream& operator>>(std::istream& st, RNA& seq);
    friend std::ostream& operator<<(std::ostream& st, RNA& seq);
    virtual bool isValid() const  ;

};


#endif // RNA_H_INCLUDED
