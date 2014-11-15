#include <iostream>
#include <stdexcept>
#include "Sequence.h"
#include <string>
#include <vector>


Sequence::Sequence(): sequence_(" "){}

Sequence::Sequence(Sequence & s): sequence_(s.sequence_){}

Sequence::Sequence(const Sequence & s): sequence_(s.sequence_){}

Sequence::Sequence(std::string s): sequence_(s){}

Sequence::~Sequence(){
}


Sequence& Sequence::operator=(const Sequence & s){

    //Tests if the assignment is necessary
    if(this == &s){

        return *this;
    }

    else{
        sequence_ = s.sequence_;
        return (*this);
    }

}


bool Sequence::operator==(const Sequence & s){

    //Tests if the sequences are equal
    if ((*this).sequence_  == s.sequence_){
        return true;
    }

    else{
        return false;
    }
}

bool Sequence::operator!=(const Sequence & s){

    //Tests if the sequences are equal
    if((*this).sequence_ == s.sequence_){
        return false;
    }
    else{
        return true;
    }

}

bool Sequence::compare(const Sequence & s, unsigned int i) const{

    //If an out_of_range exception is thrown, this try-catch block cares about it and returns false, as this indicates a wrong input
    try{

        //The program cannot test something below an index of 0
        /*if(i < 0){
            throw std::domain_error("A negative number is not allowed");
        }*/

        //If at least one of the sequences is equal to the empty string, the program will return false as a result
        if(s.sequence_ == " " || (*this).sequence_ == " "){
            return false;
        }

        //This is a counting variable for the index of the second sequence
        int counter(0);

        //If the first sequence (seen from the given point) is longer than the second sequence , this algorithm returns false
        if(s.sequence_.size() < (*this).sequence_.size() - i){
            return false;
        }

        //This is the loop which tests if the sequences are equal
        //If the second sequence is longer than the first sequence, the algorithm returns false
        for(int j = s.sequence_.size()-1; j>= 0; j--){
                if(this->sequence_.at(i) == s.sequence_.at(counter)){
                    i+=1;
                    counter+=1;
                }

                else{
                    return false;
                }
        }

        return true;

    }

    catch(std::out_of_range e){

        //If the program throws an index out of range exception
        return false;
    }
}

bool Sequence::isValid() const{
    return false;
}

unsigned int Sequence::overlap(const Sequence & s, Sequence& result) const {

    //If one of the sequences equals the empty string nothing has to be tested (it is regarded as an illegal argument)
    if(s.sequence_ == " " || (*this).sequence_ == " "){
        std::string st = "One of the sequences was the empty string ";
        st += "First: ";
        st += (*this).sequence_;
        st += " Second: ";
        st += s.sequence_;
        st += "\n";
        throw std::invalid_argument(st);
    }

    //Finding out the minimum length of the two sequences
    int minimum(1);
    int length1 = (*this).getSequence().size();
    int length2 = s.getSequence().size();

    if(length1 <= length2){
        minimum = length1;
    }

    else{
        minimum = length2;
    }

    //Creating a field where the overlappings are saved
    std::vector<unsigned int> overlappings(minimum);


    for(int i = 1; i<= minimum; i++){

        int counter1(length1 -i);
        int counter2(0);

        //Value for the number of conformities
        int conformities(0);

        while(counter2 < i){

            if((*this).sequence_.at(counter1) == s.sequence_.at(counter2)){

                //Both counters are incremented
                counter1+=1;
                counter2+=1;
                conformities+=1;

            }

            else{
                overlappings.at(i-1) = 0;
                break;
            }

        }

        if ( counter2 >= i ){

            overlappings.at(i-1) = conformities;
        }

    }


    unsigned int number(0);
    for(unsigned int i=0; i < overlappings.size(); i++)
    {
        if(overlappings.at(i) > number)
        {
            number = overlappings.at(i);
        }
    }

    std::string str = s.getSequence().substr(0, number);

    result.setSequence(str);

    //Returns the number of overlaps
    return number;
}


std::string Sequence::getSequence() const{

    return this->sequence_;
}


void Sequence::setSequence(std::string s){

    this->sequence_ = s;
}


/*Declaration of the two friend functions*/
std::istream& operator>>(std::istream& st, Sequence& seq){

    st >> seq.sequence_;

    return st;
}


std::ostream& operator<<(std::ostream& st, Sequence& seq){

    st << seq.sequence_;

    return st;
}
