#include "Extractor.h"

Extractor::Extractor(const string &path) {
    this->path = path;
    ifstream fin(this->path);
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

    vector<string> prepositions = StringHelper::get_prepositions();

    for (const string &word: this->words) {
        if (find(prepositions.begin(), prepositions.end(), word) != prepositions.end())
            total_prepositions_count++;
    }

    return double(total_prepositions_count) / double(this->words.size());
}

double Extractor::popular_letter_combination() {
    string s = StringHelper::to_lower(this->text);

    int combinations_length = 0, total_text_length = 0;

    for (const string &word: this->words) {
        for (int i = 0; i < int(word.size()) - 1; i++) {
            string sub_str = word.substr(i, 2);
            if (StringHelper::is_popular_combination(sub_str)) {
                combinations_length += 2;
            }
        }

        for (int i = 0; i < int(word.size()) - 2; i++) {
            string sub_str = word.substr(i, 3);
            if (StringHelper::is_popular_combination(sub_str)) {
                combinations_length += 3;
            }
        }
    }

    return double(combinations_length) / double(total_text_length);
}

vector<string> Extractor::get_sentences() {
    return this->sentences;
}

vector<double> Extractor::definite_contiguous_letters() {
    return {};
}

vector<double> Extractor::vowel_end_and_consonant_beginning() {
    vector<int> combinations_count(4);

    string previous_word = "";

    for (const string &word: this->words) {
        if (!previous_word.empty() && previous_word.length() >= 3 && word.length() >= 3) {
            string last_two = previous_word.substr(int(previous_word.length()) - 2, 2),
                    last_three = previous_word.substr(int(previous_word.length()) - 3, 3),
                    first_two = word.substr(0, 2),
                    first_three = word.substr(0, 3);

            combinations_count[0] += StringHelper::only_vowels(last_two) && StringHelper::only_consonants(first_two);
            combinations_count[1] += StringHelper::only_vowels(last_two) && StringHelper::only_consonants(first_three);
            combinations_count[2] += StringHelper::only_vowels(last_three) && StringHelper::only_consonants(first_two);
            combinations_count[3] += StringHelper::only_vowels(last_three) && StringHelper::only_consonants(first_three);
        }
        previous_word = word;
    }

    vector<double> result(4);

    for (int i = 0; i < 4; i++)
        result[i] = double(combinations_count[i]) / double(this->words.size());

    return result;
}

map<string, double> Extractor::get_all_info() {

    map<string, double> result;

    result["conjunctions"] = this->count_conjunctions();
    result["prepositions"] = this->count_prepositions();
    result["avg_word_length"] = this->average_word_length();
    result["avg_sentence_length"] = this->average_sentence_length();
    result["popular_combinations_proportion"] = this->popular_letter_combination();

    return result;
}
