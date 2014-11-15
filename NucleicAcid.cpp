#include "NucleicAcid.h"
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <string>



NucleicAcid::NucleicAcid(): Sequence(){}

NucleicAcid::NucleicAcid(std::string str): Sequence(str){}


NucleicAcid::NucleicAcid(NucleicAcid & na): Sequence::Sequence(na){}



NucleicAcid::~NucleicAcid(){};


NucleicAcid& NucleicAcid::operator=(const NucleicAcid & seq){
    (*this).Sequence::operator=(seq);
    return (*this);
}

/*Declaration of the two friend functions*/
std::istream& operator>>(std::istream& st, NucleicAcid& seq){

    std::string s = "";
    st >> s;
    seq.setSequence(s);

    return st;
}


std::ostream& operator<<(std::ostream& st, NucleicAcid& seq){


    std::string s = seq.getSequence();
    st << s;

    return st;
}
