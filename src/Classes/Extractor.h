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

    string text;
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
    double popular_letter_combination();

    // Proportions of word pairs with definite contiguous letters (V-V, V-C, C-V, C-C)
    vector <double> definite_contiguous_letters();

    // Proportion of word pairs with vowels at the end and consonants at the beginning  (2-2, 2-3, 3-2, 3-3)
    vector <double> vowel_end_and_consonant_beginning();

    // Methods

    // Getter for sentences field
    vector<string> get_sentences();
};

#endif //CMAKEPROJECT_EXTRACTOR_H
