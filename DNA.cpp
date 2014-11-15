#include "Sequence.h"
#include "NucleicAcid.h"
#include "DNA.h"
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <string>



DNA::DNA(): NucleicAcid(){}

DNA::DNA(std::string str):NucleicAcid(str){}


DNA::DNA(DNA & na): NucleicAcid(na){}



DNA::~DNA(){};


DNA& DNA::operator=(const DNA & seq){
    (*this).Sequence::operator=(seq);
    return (*this);
}


/*Declaration of the two friend functions*/
std::istream& operator>>(std::istream& st, DNA& seq){

    std::string s = "";
    st >> s;
    seq.setSequence(s);

    return st;
}


std::ostream& operator<<(std::ostream& st, DNA& seq){

    st << seq.getSequence();

    return st;
}

bool DNA::isValid()const{

    //If the sequence equals the empty string, no valid nucleic acid is given
    if((*this).getSequence() == " "){

        return false;

    }
    //This is the cycle for DNA
    for(unsigned int i = 0; i< (*this).getSequence().size(); i++){
        char c = (*this).getSequence().at(i);
        //Searching for the correct letter
        switch (c){
        case 'A':
            break;
        case 'T':
            break;
        case 'C':
            break;
        case 'G':
            break;
        default:
            return false;


        }
    }

    return true;
}
