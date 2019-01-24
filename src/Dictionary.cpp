#include "Dictionary.h"
#include <iostream>
#include <exception>


Dictionary::Dictionary(): rng(rd()) {
    rng.seed(static_cast<unsigned int>(time(nullptr)));
}

void Dictionary::addWord(Word __word){
    dictionary.push(__word);
    dice = std::uniform_int_distribution<>(1, dictionary.size());
}

Word& Dictionary::getRandWord() {
    if (!dictionary.size()) {
        throw ("Dictionary is empty");
    }
    return dictionary[dice(rng)];
}
