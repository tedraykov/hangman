#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "Word.h"
#include "Vector.h"
#include <random>
#include <time.h>

class Dictionary {
public:
    Dictionary();
    void addWord(Word);
    Word& getRandWord();
private:
    Vector<Word> dictionary;
    std::random_device rd;
    std::mt19937 rng;
    std::uniform_int_distribution<int> dice;
};
#endif // DICTIONARY_H
