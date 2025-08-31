#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Word {
public:
    string word;
    string definition;
    Word(){
        word = "";
        definition = "";
    }

    Word(string w, string d) {
        word = w;
        definition = d;
    }
};

vector<Word> getDictionary();

#endif
