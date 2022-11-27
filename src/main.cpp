#include <iostream>
#include <iomanip>
#include <fstream>

#include "Classes/Comparator.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    const string TEXT_FOLDER = "../texts/test";
    const int FILES_COUNT = 7;
    const bool LARGE_FILES = false;

    vector<string> files(FILES_COUNT);

    for (int i = 0; i < FILES_COUNT; i++) {
        string file_name = to_string(i + 1) + (LARGE_FILES ? "L" : "") + ".txt";
        files[i] = file_name;
    }

    Comparator comp(TEXT_FOLDER, files);

    vector<vector<double>> result = comp.compare();

    for (int i = 0; i < FILES_COUNT; i++) {
        for (int j = 0; j < FILES_COUNT; j++) {
            cout.width(7);
            cout << fixed << setprecision(2) << result[i][j] * 100 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
