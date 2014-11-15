#include "Sequence.h"
#include "NucleicAcid.h"
#include "RNA.h"
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <string>


RNA::RNA(): NucleicAcid(){}

RNA::RNA(std::string str): NucleicAcid(str){}


RNA::RNA(RNA & na): NucleicAcid(na){}



RNA::~RNA(){};


RNA& RNA::operator=(const RNA & seq){
    (*this).Sequence::operator=(seq);

    return (*this);
}


/*Declaration of the two friend functions*/
std::istream& operator>>(std::istream& st, RNA& seq){

    std::string s = "";
    st >> s;
    seq.setSequence(s);

    return st;
}


std::ostream& operator<<(std::ostream& st, RNA& seq){

    std::string s = seq.getSequence();
    st << s;

    return st;
}

bool RNA::isValid()const{

    //If the sequence equals the empty string, no valid nucleic acid is given
    if((*this).getSequence() == " "){

        return false;

    }

    //This is the cycle for RNA
    for(unsigned int i = 0; i< (*this).getSequence().size(); i++){
        char c = (*this).getSequence().at(i);
        //Searching for the correct letter
        switch (c){
        case 'A':
            break;
        case 'U':
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
