#define LOCAL_DEBUG

#include "Classes/Extractor.h"
#include "Classes/Main.h"
#include "Helpers/VectorHelper.h"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int compare() {
    ofstream fout("output.txt");
    Main m("../texts/");

    auto features = m.get_features();

    fout << "######################################################" << '\n';
    for (auto file: features) {
        for (auto[title, value]: file) {
            fout << title << ":  ";
            fout.width(50 - title.length());
            fout << fixed << setprecision(5) << value << '\n';
        }
        fout << "######################################################" << '\n';
    }

    return 0;
}

int main() {
    setlocale(LC_ALL, "ru");

    compare();
    return 0;
}
