#include "Extractor.h"

Extractor::Extractor(const string &path) {
    ifstream fin(path);
    getline(fin, this->text);

    this->sentences = StringHelper::parse_into_sentences(this->text);
    this->words = StringHelper::parse_into_words(this->text);
    this->sentences_with_words = StringHelper::parse_into_sentences_with_words(this->sentences);
}

double Extractor::average_word_length() {
    int total_text_length = 0;

    for (const string &word: this->words)
        total_text_length += int(word.size());

    return double(total_text_length) / double(words.size());
}

double Extractor::average_sentence_length() {
    return double(this->words.size()) / double(this->sentences.size());
}

double Extractor::count_conjunctions() {
    int total_conjunctions_count = 0;

    vector<string> conjunctions = StringHelper::get_conjunctions();

    for (const string &word: this->words) {
        if (find(conjunctions.begin(), conjunctions.end(), word) != conjunctions.end())
            total_conjunctions_count++;
    }

    return double(total_conjunctions_count) / double(this->words.size());
}

double Extractor::count_prepositions() {
    int total_prepositions_count = 0;

    vector<string> conjunctions = StringHelper::get_conjunctions();

    for (const string &word: this->words) {
        if (find(conjunctions.begin(), conjunctions.end(), word) != conjunctions.end())
            total_prepositions_count++;
    }

    return double(total_prepositions_count) / double(this->words.size());
}

double Extractor::letter_combination() {
    string s = StringHelper::to_lower(this->text);

    int combinations_length = 0, total_text_length = 0;

    for (const string &word: this->words) {
        for (int i = 0; i < word.size() - 1; i++) {
            string b = word.substr(i, 2);
            if (b == "ст" || b == "но" || b == "ен" || b == "то" || b == "на" || b == "ов" || b == "ни" || b == "ра" || b == "во" || b == "ко") {
                combinations_length += 2;
            }
        }
        for (int i = 0; i < word.size() - 2; i++) {
            string b = word.substr(i, 3);
            if (b == "сто" || b == "ено" || b == "нов" || b == "тов" || b == "ово" || b == "ова") {
                combinations_length += 3;
            }
        }
    }

    return double(combinations_length) / double(total_text_length);
}

vector<string> Extractor::get_sentences() {
    return this->sentences;
}
