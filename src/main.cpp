#include "Classes/Extractor.h"
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    Extractor ex("../texts/1.txt");

    auto res = ex.get_sentences();

    ofstream fout("output.txt");

    fout << res.size() << '\n';

    for (const auto &el: res)
        fout << el << '\n';

    return 0;
}
