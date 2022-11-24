#ifndef CMAKEPROJECT_EXTRACTOR_H
#define CMAKEPROJECT_EXTRACTOR_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#include "../Helpers/StringHelper.h"

using namespace std;

class Extractor {

private:
    string path;
    string text;
    int total_letter_count;

    vector<string> sentences, words;
    vector<vector<string>> sentences_with_words;

public:

    Extractor(const string &path);

//    string read_text();

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
    vector<double> definite_contiguous_letters();

    // Proportion of word pairs with vowels at the end and consonants at the beginning  (2-2, 2-3, 3-2, 3-3)
    vector<double> vowel_end_and_consonant_beginning();

    // Occurrence of each letter
    vector<double> letter_statistic();

    // Proportion of vowel and consonant letters
    vector<double> vowel_and_consonant_proportions();

    // Proportion of rare consonants
    double rare_consonants();

    // Proportion of rare letters
    double rare_letters();

    // Proportion of voiceless and voiced consonants
    vector<double> voiceless_and_voiced_consonants();

    // Proportion of combinations of three consecutive vowels and three consecutive consonants in a words
    vector<double> three_consecutive_vowels_and_consonants();

    // Methods

    // Getter for sentences field
    vector<string> get_sentences();

    // Applies all functions to text
    map<string, double> get_all_info();
};

#endif //CMAKEPROJECT_EXTRACTOR_H
