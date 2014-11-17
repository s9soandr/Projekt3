#include <iostream>
#include <string>
#include <utility>

#ifndef SEQUENCE_H
#define SEQUENCE_H


class Sequence{
private:
    std::string sequence_;
public:
    Sequence();
    Sequence(Sequence & seq);
    Sequence(const Sequence & seq);
    Sequence(std::string seq);
    ~Sequence();
    Sequence& operator=(const Sequence & seq);
    bool operator==(const Sequence & seq);
    bool operator!=(const Sequence & seq);
    friend std::istream& operator>>(std::istream& st, Sequence& seq);
    friend std::ostream& operator<<(std::ostream& st, Sequence& seq);
    bool compare(const Sequence& seq, unsigned int i) const;
    unsigned int overlap(const Sequence& seq, Sequence& result) const;
    virtual bool isValid() const;
    std::string getSequence() const;
    void setSequence(std::string seq);

    // reversiert Sequence
    void reverseSeq();
    
    // komplement
    void complementSeq();

};
#endif
