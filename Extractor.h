#ifndef CMAKEPROJECT_EXTRACTOR_H
#define CMAKEPROJECT_EXTRACTOR_H

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "StringHelper.h"

using namespace std;

class Extractor {

private:
    string text;
    vector<string> sentences, words;
    vector<vector<string>> sentences_with_words;

public:
    Extractor(const string &path);

    // Features

    // Подсчёт союзов
    double count_conjunctions();

    // Подсчёт предлогов
    double count_prepositions();

    // Средняя длина слов в тексте
    double average_word_length();

    // Средняя длина предложений в тексте
    double average_sentence_length();

    //кол-во популярных буквосочетаний / всего буквосочетаний
    double letter_combination();

    // Methods

    vector<string> get_sentences();
};

#endif //CMAKEPROJECT_EXTRACTOR_H
