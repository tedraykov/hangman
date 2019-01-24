#include "Character.h"
#include <iostream>
#include <Vector.h>


using namespace std;

Character::Character(): live_status(0) {
    for (int i = 0; i < 26; ++i) {
        sel_letters[i] = 0;
    }
}

Character::~Character() {
}

void Character::setWord(Word __word) {
    word = __word;
    guess_word = string(word.size(), '_');
}

int Character::getStatus() { return live_status; }

bool Character::isDead() { return live_status >= MAX_STAT; }

int Character::selLetter(const char &ch) {
    if (ch >= 'a' and ch <= 'z') {
        if(sel_letters[ch - 'a']) {
            cout << "Letter already used." << endl;
            return 1;
        }
        sel_letters[ch - 'a'] = 1;
    }
    else if (ch >= 'A' and ch <= 'Z'){
        if(sel_letters[ch - 'A']) {
            cout << "Letter already used." << endl;
            return 1;
        }
        sel_letters[ch - 'A'] = 1;
    } else {
        cout << "'" << ch << "'" << " is not a letter" << endl;
        return 1;
    }
    Vector<int> letterPos = word.findAllPos(ch);
    if (letterPos.isEmpty()){
        cout << "Letter not found!" << endl;
        live_status++;
        cout << MAX_STAT - getStatus() << " tries left." << endl;
        return 2;
    } else {
        for (int i = 0; i < letterPos.size(); ++i)
            guess_word[letterPos[i]] = ch;
    }
    return 3;
}

bool Character::won() {
    return guess_word == word.toString();
}

std::string Character::getWord() {
    return word.toString();
}
