#ifndef WORD_H
#define WORD_H
#include <string>
#include <iostream>
#include <Vector.h>

class Word {
public:
    Word();
    Word(std::string);
    unsigned size() const;
    const Vector<int>& findAllPos(const char& ch);
    std::string toString();
    friend std::ostream& operator<<(std::ostream& os,const Word& a);
private:
    std::string word;
};



#endif // WORD_H
