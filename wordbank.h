#ifndef HANGMAN_WORDBANK_H
#define HANGMAN_WORDBANK_H

class Wordbank {
private:
    vector<string> words;
    string word = "";
    int numChars = 0;
    vector<string> static addWords() {
        vector<string> temp;
        temp.emplace_back("byu");
        temp.emplace_back("cosmo the cougar");
        temp.emplace_back("president worthen");
        temp.emplace_back("university of utah");
        temp.emplace_back("and it came to pass");
        temp.emplace_back("wrong word");
        temp.emplace_back("tad decker made this program");
        temp.emplace_back("this is a string");
        temp.emplace_back("c plus plus");
        temp.emplace_back("rise and shout");
        return temp;
    }
public:
    Wordbank() : words(addWords()) { }

    string getRandomWord() {
        srand(time(NULL));
        int random = rand() % 10;
        word = words.at(random);
        findNumChars(word);
        return word;
    }

    void findNumChars(string word) {
        for (int i = 0; i < word.length(); i++) {
            if (word.at(i) != ' ') numChars++;
        }
    }

    int getNumChars() {
        return numChars;
    }
    string getWord() {
        return word;
    }
};


#endif //HANGMAN_WORDBANK_H
