#ifndef CMAKEPROJECT_STRINGHELPER_H
#define CMAKEPROJECT_STRINGHELPER_H

#include <string>
#include <vector>

using namespace std;

class StringHelper {

private:

    // Hide the constructor
    StringHelper() = default;

    // List of conjunctions in russian language
    inline static vector<string> conjunctions = {
            "а", "благодаря", "благо", "будто", "вдобавок", "да", "дабы", "даже", "же", "едва", "ежели", "если", "затем", "зато", "зачем", "и", "ибо", "или", "кабы", "как", "когда", "коли", "либо", "ли", "лишь", "нежели", "несмотря", "невзирая", "но", "однако",
            "оттого", "отчего", "пока", "покамест", "покуда", "поскольку", "потому", "почему", "притом", "причем", "пускай", "пусть", "раз", "словно", "также", "тоже", "только", "точно", "хотя", "чем", "что", "чтоб", "чтобы"
    };

    // List of prepositions in russian language
    inline static vector<string> prepositions = {
            "без", "близ", "в", "вместо", "вне", "для", "до", "за", "из", "из-за", "из-под", "к", "кроме", "между", "меж", "ко", "во", "безо", "на", "над", "надо", "о", "об", "обо", "от", "ото", "перед", "передо",
            "пред", "предо", "по", "под", "подо", "при", "про", "ради", "с", "со", "сквозь", "среди", "у", "через",
    };

    // List of popular letter combinations in russian language
    inline static vector<string> popular_combinations = {
            "ст", "но", "ен", "то", "на", "ов", "ни", "ра", "во", "ко", "сто", "ено", "нов", "тов", "ово", "ова"
    };


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

    // Getter for prepositions field
    static vector<string> get_prepositions();

    // Getter for popular combinations
    static vector<string> get_popular_combinations();
};

#endif //CMAKEPROJECT_STRINGHELPER_H
