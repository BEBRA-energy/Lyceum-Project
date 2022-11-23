#include "StringHelper.h"

char StringHelper::to_lower(char c) {
    if ('A' <= c && c <= 'Z')
        c += 'a' - 'A';
//    else if ('А' <= c && c <= 'Я')
//        c += 'а' - 'А';

    return c;
}

string StringHelper::to_lower(string &str) {
    string result = "";

    for (char c: str)
        result += to_lower(c);

    return result;
}

vector<string> StringHelper::parse_into_sentences(string &str) {
    string end_of_sentences = ".!?", current_sentence = "";

    vector<string> result;

    for (char c: str) {
        if (end_of_sentences.find(c) != string::npos) {
            if (!current_sentence.empty())
                result.push_back(current_sentence);
            current_sentence = "";
        } else
            current_sentence += StringHelper::to_lower(c);
    }

    return result;
}


vector<string> StringHelper::parse_into_words(string &str) {
    string end_of_word = " ,:;—.!", current_word = "";

    vector<string> result;

    for (char c: str) {
        if (end_of_word.find(c) != string::npos) {
            if (!current_word.empty())
                result.push_back(current_word);
            current_word = "";
        } else
            current_word += c;
    }

    if (!current_word.empty())
        result.push_back(current_word);

    return result;
}

vector<vector<string>> StringHelper::parse_into_sentences_with_words(vector<string> &sentences) {
    vector<vector<string>> result;

    for (string sentence: sentences) {
        vector<string> words = StringHelper::parse_into_words(sentence);
        result.push_back(words);
    }

    return result;
}

vector<string> StringHelper::get_conjunctions() {
    return StringHelper::conjunctions;
}

vector<string> StringHelper::get_prepositions() {
    return StringHelper::prepositions;
}

vector<string> StringHelper::get_popular_combinations() {
    return StringHelper::popular_combinations;
}
