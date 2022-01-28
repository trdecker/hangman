#include <iostream>
#include <string>

using namespace std;
#include "gallows.h"

void Gallows::drawGallow() {
    switch (isHung) {
        case 0:
            cout << gallows0;
            break;
        case 1:
            cout << gallows1;
            break;
        case 2:
            cout << gallows2;
            break;
        case 3:
            cout << gallows3;
            break;
        case 4:
            cout << gallows4;
            break;
        case 5:
            cout << gallows5;
            break;
        case 6:
            cout << gallows6;
            break;
        default:
            cout << gallows6;
            break;
    }
    cout << endl << "Number of guesses: (" << numGuesses << ")" << endl;
    cout << "Incorrect guesses: (" << isHung << ")" << endl;
    cout << line << endl;
}
void Gallows::endStatement() {
    if(isHung >= 6) {
        cout << lose;
        cout << endl << "Good luck next time!" << endl;
        cout << "The word was: \"" << word << "\"" << endl;
    }
    else {
        cout << congrats;
        cout << endl << "Congrats! You guessed the word in (" << numGuesses << ") guesses." << endl;
    }
}
void Gallows::checkChar(string in) {
    bool isfound = false;
    for (int i = 0; i < in.length(); i++) {
        for (int j = 0; j < word.length(); j++) {
            if (word.at(j) == in.at(i)) {
                line.at(j) = in.at(i);
                isfound = true;
            }
        }

    }
    if(isfound) cout << "Found!" << endl;
    else {
        isHung++;
        cout << "Not found!" << endl;
    }
    numGuesses++;
    drawGallow();

}

Gallows::Gallows(string input) : word(input) {
        gallows6 = "      _____\n      |    |\n     _O_   |\n      |    |\n     | |   |\n     ______|";
        gallows5 = "      _____\n      |    |\n     _O_   |\n      |    |\n     |     |\n     ______|";
        gallows4 = "      _____\n      |    |\n     _O_   |\n      |    |\n           |\n     ______|";
        gallows3 = "      _____\n      |    |\n     _O    |\n      |    |\n           |\n     ______|";
        gallows2 = "      _____\n      |    |\n      O    |\n      |    |\n           |\n     ______|";
        gallows1 = "      _____\n      |    |\n      O    |\n           |\n           |\n     ______|";
        gallows0 = "      _____\n      |    |\n           |\n           |\n           |\n     ______|";
        congrats = "      _____\n      |    |\n           |     ,I'm not dead!\n           |  _O_\n"
        "           |   |\n     ______|  | |";
        lose = "      _____\ndead  |    |\n     _O_   |\n      |    |\n     | |   |\n     ______|";

}