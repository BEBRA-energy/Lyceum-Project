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

map<string, double> Extractor::get_all_info() {
    map<string, double> result;

    result["conjunctions"] = this->conjunctions_proportions();
    result["prepositions"] = this->prepositions_proportions();
    result["pronouns"] = this->pronouns_proportion();
    result["avg_word_length"] = this->average_word_length();
    result["avg_sentence_length"] = this->average_sentence_length();
    result["popular_combinations"] = this->popular_letter_combination();
//    result["definite_contiguous_letters"] = this->definite_contiguous_letters();
//    result["vowel_end_and_consonant_beginning"] = this->vowel_end_and_consonant_beginning();

    vector<double> letter_statistic = this->letter_statistic();

    for(int i = 0;i<letter_statistic.size();i++){
        result[to_string(i)] = letter_statistic[i];
    }

    result["vowel"] = this->vowel_proportion();
    result["consonant"] = this->consonant_proportion();
    result["rare_consonants"] = this->rare_consonants();
    result["rare_letters"] = this->rare_letters();
    result["voiceless"] = this->voiceless_proportion();
    result["voiced"] = this->voiced_proportion();
    result["adjectives"] = this->adjectives_proportion();
    result["consecutive_consonants"] = this->consecutive_consonants_proportions();
    result["consecutive_vowels"] = this->consecutive_vowels_proportions();
    result["alternating_vowel_and_consonant"] = this->alternating_vowel_and_consonant();
    result["alternating_consonant_and_vowel"] = this->alternating_consonant_and_vowel();
    result["punctuation_marks"] = this->punctuation_marks_proportion();
    result["soft"] = this->soft_proportion();
    result["hard"] = this->hard_proportion();

    return result;
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

double Extractor::conjunctions_proportions() {
    int conjunctions_count = 0;
    for (const string &word: this->words) {
        conjunctions_count += StringHelper::is_conjunction(word);
    }
    return double(conjunctions_count) / double(this->words.size());
}

double Extractor::prepositions_proportions() {
    int prepositions_count = 0;
    for (const string &word: this->words) {
        prepositions_count += StringHelper::is_prepositions(word);
    }
    return double(prepositions_count) / double(this->words.size());
}

double Extractor::pronouns_proportion() {
    int pronouns_count = 0;
    for (const string &word: this->words) {
        pronouns_count += StringHelper::is_pronoun(word);
    }
    return double(pronouns_count) / double(this->total_letter_count);
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

vector<double> Extractor::letter_statistic() {
    vector<int> letters_count(33);
    for (const string &word: this->words) {
        for (char c: word) {
            if (!StringHelper::is_letter(c)) continue;
            int letter_index = c - '�';
            letters_count[letter_index]++;
        }
    }
    vector<double> result(33);
    for (int i = 0; i < 33; i++)
        result[i] = double(letters_count[i]) / double(this->total_letter_count);
    return result;
}

double Extractor::consonant_proportion() {
    int result = 0;
    for (const string &word: this->words) {
        for (char c: word)
            result += StringHelper::is_consonant(c);
    }
    return double(result) / double(this->total_letter_count);
}

double Extractor::vowel_proportion() {
    int result = 0;
    for (const string &word: this->words) {
        for (char c: word)
            result += StringHelper::is_vowel(c);
    }
    return double(result) / double(this->total_letter_count);
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
//voiceless_and_voiced_consonants

double Extractor::voiced_proportion() {
    int result = 0;
    for (const string &word: this->words) {
        for (char c: word)
            result += StringHelper::is_voiced(c);
    }
    return double(result) / double(this->total_letter_count);
}

double Extractor::voiceless_proportion() {
    int result = 0;
    for (const string &word: this->words) {
        for (char c: word)
            result += StringHelper::is_voiceless(c);
    }
    return double(result) / double(this->total_letter_count);
}

vector<double> Extractor::three_consecutive_vowels_and_consonants() {
    int three_consecutive_vowels = 0, three_consecutive_consonants = 0, possible_combinations_count = 0;
    for (const string &word: this->words) {
        for (int i = 0; i < int(word.length()) - 3; i++) {
            string sub_str = word.substr(i, 3);
            possible_combinations_count++;
            three_consecutive_consonants += StringHelper::only_consonants(sub_str);
            three_consecutive_vowels += StringHelper::only_vowels(sub_str);
        }
    }
    return {
            double(three_consecutive_vowels) / double(possible_combinations_count),
            double(three_consecutive_vowels) / double(possible_combinations_count)
    };
}

double Extractor::adjectives_proportion() {
    int adjectives_count = 0;
    for (const string &s: this->words) {
        adjectives_count += StringHelper::is_adjective(s);
    }
    return double(adjectives_count) / double(this->words.size());
}

map<string, double> Extractor::words_popularity() {
    map<string, int> count;
    map<string, double> result;
    for (const string &s: this->words) {
        count[s]++;
    }
    for (auto &[word, cnt]: result) {
        result[word] = double(cnt) / double(this->words.size());
    }
    return result;
}

double Extractor::consecutive_consonants_proportions() {
    int size = 0, result = 0;
    for (string s: this->words) {
        size += s.size() - 1;
        for (int i = 1; i < s.size(); i++) {
            result += StringHelper::is_consonant(s[i]) && StringHelper::is_consonant(s[i - 1]);
        }
    }
    return double(result) / double(size);
}

double Extractor::consecutive_vowels_proportions() {
    int size = 0, result = 0;
    for (string s: this->words) {
        size += s.size() - 1;
        for (int i = 1; i < s.size(); i++) {
            result += StringHelper::is_vowel(s[i]) && StringHelper::is_vowel(s[i - 1]);
        }
    }
    return double(result) / double(size);
}

double Extractor::alternating_vowel_and_consonant() {
    int size = 0, result = 0;
    for (string s: this->words) {
        size += s.size() - 1;
        for (int i = 1; i < s.size(); i++) {
            result += StringHelper::is_vowel(s[i]) && StringHelper::is_consonant(s[i - 1]);
        }
    }
    return double(result) / double(size);
}

double Extractor::alternating_consonant_and_vowel() {
    int possible_combinations_count = 0, result = 0;
    for (string s: this->words) {
        possible_combinations_count += int(s.size()) - 1;
        for (int i = 1; i < s.size(); i++) {
            result += StringHelper::is_consonant(s[i]) && StringHelper::is_vowel(s[i - 1]);
        }
    }
    return double(result) / double(possible_combinations_count);
}

double Extractor::punctuation_marks_proportion() {
    int result = 0;
    for (char c: this->text) {
        result += StringHelper::is_punctuation_mark(c);
    }
    return double(result) / double(this->sentences.size());
}

double Extractor::soft_proportion() {
    int soft_count = 0;
    int consonant_count = 0;
    for (string word: this->words) {
        for (int i = 1; i < word.size(); i++) {
            consonant_count += StringHelper::is_consonant(word[i - 1]);
            soft_count += !StringHelper::is_soft(word[i - 1])
                          && !StringHelper::is_hard(word[i - 1])
                          && StringHelper::is_softener(word[i]);
        }
        for (char c: word) {
            soft_count += StringHelper::is_soft(c);
        }
    }
    return double(soft_count) / double(consonant_count);
}


double Extractor::hard_proportion() {
    int hard_count = 0;
    int consonant_count = 0;
    for (string word: this->words) {
        for (int i = 1; i < word.size(); i++) {
            consonant_count += StringHelper::is_consonant(word[i - 1]);
            hard_count += !StringHelper::is_hard(word[i - 1])
                          && !StringHelper::is_soft(word[i - 1])
                          && !StringHelper::is_softener(word[i]);
        }
        for (char c: word) {
            hard_count += StringHelper::is_hard(c);
        }
    }
    return double(hard_count) / double(consonant_count);
}