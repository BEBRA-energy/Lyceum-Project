#define LOCAL_DEBUG

#include "Classes/Extractor.h"
#include "Classes/main.h"
#include "Helpers/VectorHelper.h"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void compare() {
    ofstream fout("output.txt");
    Main m("../texts/");

    auto features = m.get_features();

    fout << "######################################################" << '\n';
    for (const auto &file: features) {
        for (auto[title, value]: file) {
            fout << title << ":  ";
            fout.width(50 - title.length());
            fout << fixed << setprecision(5) << value << '\n';
        }
        fout << "######################################################" << '\n';
    }
    
    vector<vector<double>> values_only;
    for(map<string, double> text_features: features){
        vector<double> text_values; 
        for(auto value: text_features)
            text_values.push_back(value.second);
        values_only.push_back(text_values);
    }

    int num_texts = values_only.size();
    ofstream fout("output.txt");
    for(int i =1;i<=num_texts;i++){
        vector<double> i_vector_similarities;
        for(int j = 1;j<=num_texts;j++){
            vector<double> text1 = values_only[i];
            vector<double> text2 = values_only[j];
            fout<<"text "<<i<<" and "<<j<<VectorHelper::cosine_similarity(text1, text2)<<endl;
        }
    } 
}

int main() {
    setlocale(LC_ALL, "ru");

    compare();
    return 0;
}
