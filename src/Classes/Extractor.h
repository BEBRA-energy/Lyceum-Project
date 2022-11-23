#ifndef CMAKEPROJECT_EXTRACTOR_H
#define CMAKEPROJECT_EXTRACTOR_H

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include "../Helpers/StringHelper.h"

using namespace std;

class Extractor {

private:

    const string text;
    vector<string> sentences, words;
    vector<vector<string>> sentences_with_words;

public:

    Extractor(const string &path);

    // Features

    // Conjunctions count
    double count_conjunctions();

    // Preposition count
    double count_prepositions();

    // Average word length
    double average_word_length();

    // Average sentence length (in words)
    double average_sentence_length();

    // Proportion of popular letter combinations
    double letter_combination();

    // Methods

    // Getter for sentences field
    vector<string> get_sentences();

    // applys all functions to text
    map<string, double> get_all_info();
};

#endif //CMAKEPROJECT_EXTRACTOR_H
