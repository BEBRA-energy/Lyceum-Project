#ifndef CMAKEPROJECT_STRINGHELPER_H
#define CMAKEPROJECT_STRINGHELPER_H

#include <string>
#include <vector>

using namespace std;

class StringHelper {
private:
    inline static vector<string> conjunctions = {
            "а", "благодаря", "благо", "будто", "вдобавок", "да", "дабы", "даже", "же", "едва", "ежели", "если", "затем", "зато", "зачем", "и", "ибо", "или", "кабы", "как", "когда", "коли", "либо", "ли", "лишь", "нежели", "несмотря", "невзирая", "но", "однако",
            "оттого", "отчего", "пока", "покамест", "покуда", "поскольку", "потому", "почему", "притом", "причем", "пускай", "пусть", "раз", "словно", "также", "тоже", "только", "точно", "хотя", "чем", "что", "чтоб", "чтобы"};

    inline static vector<string> prepositions = {
            "без", "близ", "в", "вместо", "вне", "для", "до", "за", "из", "из-за", "из-под", "к", "кроме", "между", "меж", "ко", "во", "безо", "на", "над", "надо", "о", "об", "обо", "от", "ото", "перед", "передо",
            "пред", "предо", "по", "под", "подо", "при", "про", "ради", "с", "со", "сквозь", "среди", "у", "через",
    };

public:
    static char to_lower(char c);

    static string to_lower(string &str);

    static vector<string> parse_into_sentences(string &str);

    static vector<string> parse_into_words(string &str);

    static vector<vector<string>> parse_into_sentences_with_words(vector<string> &sentences);

    static vector<string> get_conjunctions();

    static vector<string> get_prepositions();
};

#endif //CMAKEPROJECT_STRINGHELPER_H
