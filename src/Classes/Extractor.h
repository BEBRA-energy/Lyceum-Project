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

    // Proportion of conjunctions
    double conjunctions_proportions();

    // Proportion of preposition
    double prepositions_proportions();

    // Proportion of pronouns
    double pronouns_proportion();

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

    // Proportion of vowel letters
    double vowel_proportion();

    // Proportion of consonant letters
    double consonant_proportion();

    // Proportion of rare consonants
    double rare_consonants();

    // Proportion of rare letters
    double rare_letters();

    // Proportion of voiceless consonants
    double voiceless_proportion();

    // Proportion of voiced consonants
    double voiced_proportion();

    // Proportion of combinations of three consecutive vowels and three consecutive consonants in a words
    vector<double> three_consecutive_vowels_and_consonants();

    // Proportion of adjectives in text
    double adjectives_proportion();

    // Most used words
    map<string, double> words_popularity();

    // Consecutive consonants
    double consecutive_consonants_proportions();

    // Consecutive vowels
    double consecutive_vowels_proportions();

    // Alternating vowel and consonant
    double alternating_vowel_and_consonant();

    // Alternating consonant and vowel
    double alternating_consonant_and_vowel();

    // Punctuation marks
    double punctuation_marks_proportion();

    // Proportion of soft consonants
    double soft_proportion();

    // Proportion of hard consonants
    double hard_proportion();

    // Methods

    // Applies all functions to text
    map<string, double> get_all_info();
};

#endif //CMAKEPROJECT_EXTRACTOR_H
