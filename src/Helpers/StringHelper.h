#ifndef CMAKEPROJECT_STRINGHELPER_H
#define CMAKEPROJECT_STRINGHELPER_H

#include <string>
#include <vector>
#include <algorithm>

#include "StdVectorHelper.h"

using namespace std;

class StringHelper {

private:
    // Hide the constructor
    StringHelper() = default;

    inline const static double average_word_length = 5.28, average_sentence_length = 10.38;

    // List of conjunctions in russian language
    inline const static vector<string> conjunctions = {
            "а", "благодаря", "благо", "будто", "вдобавок", "да", "дабы", "даже", "же", "едва", "ежели", "если", "затем", "зато", "зачем", "и", "ибо", "или", "кабы", "как", "когда", "коли", "либо", "ли", "лишь", "нежели", "несмотря", "невзирая", "но", "однако",
            "оттого", "отчего", "пока", "покамест", "покуда", "поскольку", "потому", "почему", "притом", "причем", "пускай", "пусть", "раз", "словно", "также", "тоже", "только", "точно", "хотя", "чем", "что", "чтоб", "чтобы"
    };

    // List of prepositions in russian language
    inline const static vector<string> prepositions = {
            "без", "близ", "в", "вместо", "вне", "для", "до", "за", "из", "из-за", "из-под", "к", "кроме", "между", "меж", "ко", "во", "безо", "на", "над", "надо", "о", "об", "обо", "от", "ото", "перед", "передо",
            "пред", "предо", "по", "под", "подо", "при", "про", "ради", "с", "со", "сквозь", "среди", "у", "через",
    };

    // List of popular letter combinations in russian language
    inline const static vector<string> popular_combinations = {
            "ст", "но", "ен", "то", "на", "ов", "ни", "ра", "во", "ко", "сто", "ено", "нов", "тов", "ово", "ова"
    };

    // List of vowel letters in russian language
    inline const static vector<char> vowel_letters = {'а', 'о', 'у', 'э', 'е', 'и', 'ё', 'я', 'ю', 'ы'};

    // List of consonant letters in russian language
    inline const static vector<char> consonant_letters = {'й', 'ц', 'к', 'н', 'г', 'ш', 'щ', 'з', 'х', 'ъ', 'ф', 'в', 'п', 'р', 'л', 'д', 'ж', 'ч', 'с', 'м', 'т', 'ь', 'б'};

    // List of rare consonants
    inline const static vector<char> rare_consonants = {'ф', 'ч', 'х', 'ц', 'щ', 'ш', 'ж'};

    // List of rare letters
    inline const static vector<char> rare_letters = {'ы', 'ъ', 'ь', 'й'};

    // List of voiceless consonants
    inline const static vector<char> voiceless_consonants = {'п', 'ф', 'т', 'с', 'ш', 'к', 'ч', 'щ', 'ц', 'х'};

    // List of voices consonants
    inline const static vector<char> voiced_consonants = {'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'л', 'м', 'н', 'р'};


public:

    // Char to lower case
    static char to_lower(char c);

    // String to lower case
    static string to_lower(const string &str);

    // Parse string into sentences
    static vector<string> parse_into_sentences(const string &str);

    // Parse string into words
    static vector<string> parse_into_words(const string &str);

    // Parse sentences into words
    static vector<vector<string>> parse_into_sentences_with_words(const vector<string> &sentences);

    // Getter for conjunctions field
    static vector<string> get_conjunctions();

    // Check if the word is conjunction
    static bool is_conjunction(const string &word);

    // Getter for prepositions field
    static vector<string> get_prepositions();

    // Check if the word is preposition
    static bool is_prepositions(const string &word);

    // Getter for popular letter combinations
    static vector<string> get_popular_combinations();

    // Check if the word is popular letter combination
    static bool is_popular_combination(const string &word);

    // Check if a letter is a vowel
    static bool is_vowel(char c);

    // Check if a letter is consonant
    static bool is_consonant(char c);

    // Check if is letter
    static bool is_letter(char c);

    // Check if is a rare consonant
    static bool is_rare_consonant(char c);

    // Check if is a rare letter
    static bool is_rare_letter(char c);

    // Check if a string consists of only vowel letters
    static bool only_vowels(const string &str);

    // Check if a string consists of only consonant letters
    static bool only_consonants(const string &str);

    // Count letters in a string
    static int count_letters(const string &str);

    // Check if is voiceless
    static bool is_voiceless(char c);

    // Check if is voiced
    static bool is_voiced(char c);
};

#endif //CMAKEPROJECT_STRINGHELPER_H
