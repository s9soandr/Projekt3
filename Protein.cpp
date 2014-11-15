#include "Protein.h"
#include "Sequence.h"
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <string>

Protein::Protein():Sequence() {}

Protein::Protein(std::string str): Sequence(str) {}

Protein::Protein(Protein & p): Sequence::Sequence(p){}



Protein::~Protein(){};


Protein& Protein::operator=(const Protein & seq){
    (*this).Sequence::operator=(seq);
    return (*this);
}



bool Protein::isValid() const{

    //If the sequence equals the empty string, no valid protein is given
    if((*this).getSequence() == " "){

        return false;

    }

    //This is the cycle for the protein
    for(unsigned int i = 0; i< (*this).getSequence().size(); i++){
        char c = (*this).getSequence().at(i);
        //Searching for the correct letter
        switch (c){
        case 'A':
            break;
        case 'R':
            break;
        case 'N':
            break;
        case 'D':
            break;
        case 'C':
            break;
        case 'Q':
            break;
        case 'E':
            break;
        case 'G':
            break;
        case 'H':
            break;
        case 'I':
            break;
        case 'L':
            break;
        case 'K':
            break;
        case 'M':
            break;
        case 'F':
            break;
        case 'P':
            break;
        case 'S':
            break;
        case 'T':
            break;
        case 'V':
            break;
        case 'W':
            break;
        case 'Y':
            break;
        default:
            return false;


        }
    }

    return true;
}


/*Declaration of the two friend functions*/
std::istream& operator>>(std::istream& st, Protein& seq){

    std::string s = "";
    st >> s;
    seq.setSequence(s);

    return st;
}


std::ostream& operator<<(std::ostream& st, Protein& seq){

    std::string s = seq.getSequence();
    st << s;

    return st;
}

