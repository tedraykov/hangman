#include "Game.h"

using namespace std;

Game::Game(): end_game(false) {
}

Game::~Game() {
}

void Game::resetGame() {
    character = Character();
    end_game = false;
}

void Game::initGame() {
    ifstream file;
    file.open("input.txt");
    string __word;
    if (file.is_open()) {
        //Initializing the dictionary with the words from the input file
        while (file >> __word)
            dictionary.addWord(Word(__word));

        //Setting character's word

        while (!end_game) {
            resetGame();
            character.setWord(
                    dictionary.getRandWord()
            );
            char sel_letter;
            cout << character.guess_word << endl;
            while(!character.isDead()){
                cout << "Enter a letter: ";
                cin >> sel_letter;
                if(character.selLetter(sel_letter) == 3) {
                    cout << character.guess_word << endl;
                    if (character.won()) {
                        cout << "You won the game!" << endl;
                        break;
                    }
                }
            }
            if (!character.won()) cout << "Your word was: " << character.getWord() << endl;
            cout << "You want to play again?    Y/n" << endl;
            cin >> sel_letter;
            if (sel_letter == 'n' or sel_letter == 'N') end_game = true;
        }
        cout << "Goodbye!" << endl;
    } else {
        cout << "File cannot be opened!" << endl <<
             "Game terminated" << endl;
    }
}
