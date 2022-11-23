#include "Extractor.h"
#include "../Helpers/StringHelper.h"

Extractor::Extractor(string &path) {
    ifstream fin(path);
    this->path = path;

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

    vector<string> prepositions = StringHelper::get_prepositions();

    for (const string &word: this->words) {
        if (find(prepositions.begin(), prepositions.end(), word) != prepositions.end())
            total_prepositions_count++;
    }

    return double(total_prepositions_count) / double(this->words.size());
}

double Extractor::letter_combination() {
    string s = StringHelper::to_lower(this->text);

    int combinations_length = 0, total_text_length = 0;

    for (const string &word: this->words) {
        vector<string> popular_combinations = StringHelper::get_popular_combinations();

        for (int i = 0; i < int(word.size()) - 1; i++) {
            string b = word.substr(i, 2);
            if (find(popular_combinations.begin(), popular_combinations.end(), b) != popular_combinations.end()) {
                combinations_length += 2;
            }
        }

        for (int i = 0; i < int(word.size()) - 2; i++) {
            string b = word.substr(i, 3);
            if (find(popular_combinations.begin(), popular_combinations.end(), b) != popular_combinations.end()) {
                combinations_length += 3;
            }
        }
    }

    return double(combinations_length) / double(total_text_length);
}

vector<string> Extractor::get_sentences() {
    return this->sentences;
}

map<string, double> Extractor::get_all_info(){

    map<string, double> result;

    result["conjunctions"] = this->count_conjunctions();
    result["prepositions"] = this->count_prepositions();
    result["avg_word_length"] = this->average_word_length();
    result["avg_sentence_length"] = this->average_sentence_length();
    result["popular_combinations_proportion"] = this->letter_combination();
    
    return result;
}
