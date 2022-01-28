#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "wordbank.h"
#include "gallows.h"

void runGame();

int main() {
    string response = "x";


    cout << "Welcome to Hangman! Enter Y to begin." << endl;
    cin >> response;
    if ((response == "y") || (response == "Y")) runGame();
    cout << "Thank you for playing!";
    return 0;
}

void runGame() {
    string word = "";
    Wordbank bank;
    string response = "";
    word = bank.getRandomWord();
    bank.getWord();
    bank.getNumChars();
    cout << "Word has only lowercase leters, and is " << bank.getNumChars() << " letters long." << endl;
    Gallows gallow(word);
    gallow.createGallows();
    gallow.createSpaces();
    while (!gallow.checkEnd()) {
        cout << endl << "Guess a letter!" << endl;
        cin >> response;
        gallow.checkChar(response);
    }
    gallow.endStatement();
    cout << "Play again? (Y/N)" << endl;
    cin >> response;
    if ((response == "y") || (response == "Y")) runGame();
    else return;
}
