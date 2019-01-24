#ifndef CHARACTER_H
#define CHARACTER_H

#include "Word.h"
#include "Vector.h"

const int MAX_STAT = 6;

class Character {
public:
    Character();
    ~Character();
    void setWord(Word);
    std::string getWord();
    int getStatus();
    bool isDead();
    int selLetter(const char& ch);
    bool won();
    std::string guess_word;
private:
    Word word;
    int live_status;
    bool sel_letters[26];
};

#endif // CHARACTER_H
