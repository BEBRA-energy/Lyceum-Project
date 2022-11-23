#include "Classes/Extractor.h"
#include <iostream>

using namespace std;

int main() {
    Extractor ex("../texts/0.txt");

    auto res = ex.get_sentences();

    cout << res.size() << '\n';

    for (const auto &el: res)
        cout << el << '\n';

    return 0;
}
