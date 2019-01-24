#ifndef GAME_H
#define GAME_H

#include <fstream>
#include "Dictionary.h"
#include "Word.h"
#include "Character.h"

using  namespace std;

class Game {
public:
    Game();
    ~Game();
    void initGame();
    void resetGame();
private:
    Dictionary dictionary;
    Character character;
    bool end_game;
};

#endif // GAME_H
