#define LOCAL_DEBUG

#include "Classes/Extractor.h"
//#include "Classes/main.h"
#include "Helpers/VectorHelper.h"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//void print() {
//   ofstream fout("features.txt");
//   Main m("../texts/");
//   auto features = m.get_features();
//   fout << "######################################################" << '\n';
//   for (const auto &file: features) {
//       for (auto[title, value]: file) {
//           fout << title << ":  ";
//           fout.width(50 - int(title.length()));
//           fout << fixed << setprecision(5) << value << '\n';
//       }
//       fout << "######################################################" << '\n';
//   }
//}

void compare(const string &text_folder) {
    ofstream fout("features.txt");

    vector<map<string, double>> features;
    for (int i = 1; i <= 4; i++) {
        string path = text_folder + to_string(i) + ".txt";
        Extractor extractor(path);
        features.push_back(extractor.get_all_info());
    }

    vector<vector<double>> values_only;
    for (const map<string, double> &text_features: features) {
        vector<double> text_values;
        for (const auto &value: text_features)
            text_values.push_back(value.second);
        values_only.push_back(text_values);
    }

    int num_texts = values_only.size();
    ofstream res_stream("output.txt");
    for (int i = 1; i <= num_texts; i++) {
        for (int j = 1; j <= num_texts; j++) {
            vector<double> text1 = values_only[i - 1];
            vector<double> text2 = values_only[j - 1];
            res_stream << "text " << i << " and " << j << " " << VectorHelper::cosine_similarity(text1, text2) << endl;
        }
        res_stream << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    const string TEXT_FOLDER = "../texts/";
    //print();
    compare(TEXT_FOLDER);
    return 0;
}
