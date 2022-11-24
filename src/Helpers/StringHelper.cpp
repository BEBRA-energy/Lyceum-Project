#include "StringHelper.h"

char StringHelper::to_lower(char c) {
    if ('A' <= c && c <= 'Z')
        c += 'a' - 'A';
    else if ('À' <= c && c <= 'ß')
        c += 'à' - 'À';
    return c;
}

string StringHelper::to_lower(const string &str) {
    string result = "";
    for (char c: str)
        result += to_lower(c);
    return result;
}

vector<string> StringHelper::parse_into_sentences(const string &str) {
    vector<string> result;
    string end_of_sentences = ".!?", current_sentence = "";
    for (char c: str) {
        if (end_of_sentences.find(c) != string::npos) {
            if (!current_sentence.empty())
                result.push_back(current_sentence);
            current_sentence = "";
        } else if (!current_sentence.empty() || c != ' ')
            current_sentence += StringHelper::to_lower(c);
    }
    return result;
}


vector<string> StringHelper::parse_into_words(const string &str) {
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

vector<vector<string>> StringHelper::parse_into_sentences_with_words(const vector<string> &sentences) {
    vector<vector<string >> result;

    for (string sentence: sentences) {
        vector<string> words = StringHelper::parse_into_words(sentence);
        result.push_back(words);
    }

    return result;
}

bool StringHelper::is_vowel(char c) {
    return StdVectorHelper::is_in_vector(StringHelper::vowel_letters, StringHelper::to_lower(c));
}

bool StringHelper::is_consonant(char c) {
    return StdVectorHelper::is_in_vector(StringHelper::consonant_letters, StringHelper::to_lower(c));
}

bool StringHelper::is_conjunction(const string &word) {
    return StdVectorHelper::is_in_vector(StringHelper::conjunctions, StringHelper::to_lower(word));
}

bool StringHelper::is_prepositions(const string &word) {
    return StdVectorHelper::is_in_vector(StringHelper::prepositions, StringHelper::to_lower(word));
}

bool StringHelper::is_popular_combination(const string &word) {
    return StdVectorHelper::is_in_vector(StringHelper::popular_combinations, StringHelper::to_lower(word));
}

bool StringHelper::only_vowels(const string &str) {
    for (char c: str) {
        if (!StringHelper::is_vowel(c))
            return false;
    }
    return true;
}

bool StringHelper::only_consonants(const string &str) {
    for (char c: str) {
        if (!StringHelper::is_consonant(c))
            return false;
    }
    return true;
}

bool StringHelper::is_letter(char c) {
    return StringHelper::is_vowel(c) || StringHelper::is_consonant(c);
}

bool StringHelper::is_rare_consonant(char c) {
    return StdVectorHelper::is_in_vector(StringHelper::rare_consonants, StringHelper::to_lower(c));
}

bool StringHelper::is_rare_letter(char c) {
    return StdVectorHelper::is_in_vector(StringHelper::rare_letters, StringHelper::to_lower(c));
}

int StringHelper::count_letters(const string &str) {
    int result = 0;
    for (char c: str)
        result += StringHelper::is_letter(c);
    return result;
}

bool StringHelper::is_voiceless(char c) {
    return StdVectorHelper::is_in_vector(StringHelper::voiceless_consonants, StringHelper::to_lower(c));
}

bool StringHelper::is_voiced(char c) {
    return StdVectorHelper::is_in_vector(StringHelper::voiced_consonants, StringHelper::to_lower(c));
}

bool StringHelper::is_adjective(const string &str) {
    if (str.size() < 5) return false;

    string two_letter_ending = StringHelper::to_lower(str.substr(int(str.length()) - 2, 2));
    string three_letter_ending = StringHelper::to_lower(str.substr(int(str.length()) - 3, 3));

    return StdVectorHelper::is_in_vector(StringHelper::adjective_ends, two_letter_ending)
           || StdVectorHelper::is_in_vector(StringHelper::adjective_ends, three_letter_ending);
}

bool StringHelper::is_punctuation_mark(char c) {
    return StdVectorHelper::is_in_vector(StringHelper::punctuation_marks, StringHelper::to_lower(c));
}

