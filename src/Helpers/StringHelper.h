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

    // List of conjunctions in russian language
    inline const static vector<string> conjunctions = {
            "�", "���������", "�����", "�����", "��������", "��", "����", "����", "��", "����", "�����", "����", "�����", "����", "�����", "�", "���", "���", "����", "���", "�����", "����", "����", "��", "����", "������", "��������", "��������", "��", "������",
            "������", "������", "����", "��������", "������", "���������", "������", "������", "������", "������", "������", "�����", "���", "������", "�����", "����", "������", "�����", "����", "���", "���", "����", "�����"
    };

    // List of prepositions in russian language
    inline const static vector<string> prepositions = {
            "���", "����", "�", "������", "���", "���", "��", "��", "��", "��-��", "��-���", "�", "�����", "�����", "���", "��", "��", "����", "��", "���", "����", "�", "��", "���", "��", "���", "�����", "������",
            "����", "�����", "��", "���", "����", "���", "���", "����", "�", "��", "������", "�����", "�", "�����",
    };

    // List of popular letter combinations in russian language
    inline const static vector<string> popular_combinations = {
            "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "���", "���", "���", "���", "���", "���"
    };

    // List of vowel letters in russian language
    inline const static vector<char> vowel_letters = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};

    // List of consonant letters in russian language
    inline const static vector<char> consonant_letters = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};

public:

    // Char to lower case
    static char to_lower(char c);

    // String to lower case
    static string to_lower(string &str);

    // Parse string into sentences
    static vector<string> parse_into_sentences(string &str);

    // Parse string into words
    static vector<string> parse_into_words(string &str);

    // Parse sentences into words
    static vector<vector<string>> parse_into_sentences_with_words(vector<string> &sentences);

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
};

#endif //CMAKEPROJECT_STRINGHELPER_H
