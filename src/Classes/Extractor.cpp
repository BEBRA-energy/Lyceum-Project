#include "Extractor.h"

Extractor::Extractor(const string &path) {
    this->path = path;
    ifstream fin(this->path);
    getline(fin, this->text);

    cout << this->path << '\n';

    this->sentences = StringHelper::parse_into_sentences(this->text);
    this->words = StringHelper::parse_into_words(this->text);
    this->sentences_with_words = StringHelper::parse_into_sentences_with_words(this->sentences);
    this->total_letter_count = StringHelper::count_letters(this->text);
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

    int combinations_length = 0;

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

    return double(combinations_length) / double(this->total_letter_count);
}

vector<string> Extractor::get_sentences() {
    return this->sentences;
}

vector<double> Extractor::definite_contiguous_letters() {
    vector<int> combinations_count(4);

    for (const vector<string> &sentence: this->sentences_with_words) {
        string previous_word = "";

        for (const string &word: sentence) {
            if (!previous_word.empty() && previous_word.length() >= 3 && word.length() >= 3) {
                char last = previous_word.back(), first = word.front();

                combinations_count[0] += StringHelper::is_vowel(last) && StringHelper::is_vowel(first);
                combinations_count[1] += StringHelper::is_vowel(last) && StringHelper::is_consonant(first);
                combinations_count[2] += StringHelper::is_consonant(last) && StringHelper::is_vowel(first);
                combinations_count[3] += StringHelper::is_consonant(last) && StringHelper::is_consonant(first);
            }
            previous_word = word;
        }
    }

    vector<double> result(4);

    for (int i = 0; i < 4; i++)
        result[i] = double(combinations_count[i]) / double(this->words.size());

    return result;
}

vector<double> Extractor::vowel_end_and_consonant_beginning() {
    vector<int> combinations_count(4);

    for (const vector<string> &sentence: this->sentences_with_words) {
        string previous_word = "";

        for (const string &word: sentence) {
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
//    result["definite_contiguous_letters"] = this->definite_contiguous_letters();
//    result["vowel_end_and_consonant_beginning"] = this->vowel_end_and_consonant_beginning();
//    result["letter_statistic"] = this->letter_statistic();
//    result["vowel_and_consonant_proportions"] = this->vowel_and_consonant_proportions();
    auto voiceless_and_voiced_consonants = this->voiceless_and_voiced_consonants();
    result["voiceless_proportion"] = voiceless_and_voiced_consonants[0];
    result["voiced_proportion"] = voiceless_and_voiced_consonants[1];
    result["rare_consonants"] = this->rare_consonants();
    result["rare_letters"] = this->rare_letters();

    return result;
}

vector<double> Extractor::letter_statistic() {
    vector<int> letters_count(33);
    for (const string &word: this->words) {
        for (char c: word) {
            if (!StringHelper::is_letter(c)) continue;
            int letter_index = c - 'à';
            letters_count[letter_index]++;
        }
    }
    vector<double> result(33);
    for (int i = 0; i < 33; i++)
        result[i] = double(letters_count[i]) / double(this->total_letter_count);
    return result;
}

vector<double> Extractor::vowel_and_consonant_proportions() {
    int vowel_count = 0, consonant_count = 0;
    for (const string &word: this->words) {
        for (char c: word) {
            vowel_count += StringHelper::is_vowel(c);
            consonant_count += StringHelper::is_consonant(c);
        }
    }
    return {
            double(vowel_count) / double(this->total_letter_count),
            double(consonant_count) / double(this->total_letter_count)
    };
}

double Extractor::rare_consonants() {
    int rare_consonants_count = 0;
    for (const string &word: this->words) {
        for (char c: word)
            rare_consonants_count += StringHelper::is_rare_consonant(c);
    }
    return double(rare_consonants_count) / double(this->total_letter_count);
}

double Extractor::rare_letters() {
    int rare_letters_count = 0;
    for (const string &word: this->words) {
        for (char c: word)
            rare_letters_count += StringHelper::is_rare_letter(c);
    }
    return double(rare_letters_count) / double(this->total_letter_count);
}

vector<double> Extractor::voiceless_and_voiced_consonants() {
    int voiceless_count = 0, voiced_count = 0;
    for (const string &word: this->words) {
        for (char c: word) {
            voiceless_count += StringHelper::is_voiceless(c);
            voiced_count += StringHelper::is_voiced(c);
        }
    }
    return {
            double(voiceless_count) / double(this->total_letter_count),
            double(voiced_count) / double(this->total_letter_count)
    };
}

double Extractor::adjectives() {
    int cnt = 0;
    for (const string &s: this->words) {
        cnt += StringHelper::is_adjective(s);
    }
    return double(cnt) / double(this->total_letter_count);
}

map<string, double> Extractor::words_popularity() {
    map<string, double> result;
    for (const string &s: this->words) {
        result[s]++;
    }
    for (auto &it: result) {
        it.second /= double(this->words.size());
    }
    return result;
}
