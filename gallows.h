#ifndef HANGMAN_GALLOWS_H
#define HANGMAN_GALLOWS_H

using namespace std;

class Gallows {
private:
    string word;
    string gallows0, gallows1, gallows2, gallows3, gallows4, gallows5, gallows6, congrats, lose;
    string line;
    unsigned int numGuesses = 0;
    unsigned int isHung = 0;
    bool won = false;
public:
    Gallows(string input);
    void createGallows() {
        cout << gallows0 << endl;
    }
    void createSpaces() {
        for (int i = 0; i < word.length(); i++) {
            if (word.at(i) != ' ') line.append("_");
            else line.append(" ");
        }
        cout << line << endl;
    }
    void checkChar(string in);
    void drawGallow();
    void endStatement();
    bool checkEnd() {
        if (word == line) {
            won = true;
            return true;
        }
        else if (isHung >= 6) return true;
        else return false;
    }
};

#endif //HANGMAN_GALLOWS_H
