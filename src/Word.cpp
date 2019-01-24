#include "Word.h"
#include <iostream>
#include <Vector.h>

Word::Word(){
}

Word::Word(std::string __word) {
    word = __word;
}

std::ostream& operator<<(std::ostream& os,const Word& a){
    return os << a.word;
}

unsigned Word::size() const { return word.length(); }

const Vector<int>& Word::findAllPos(const char& ch) {
    Vector<int>* allLettersPos = new Vector<int>;

    for (unsigned i = 0; i < word.size(); ++i)
        if (ch == word[i])
            allLettersPos->push(i);

    return *allLettersPos;
}

std::string Word::toString() {
    return word;
}
