#include "Classes/Extractor.h"
#include "Helpers/VectorHelper.h"

#include <iostream>
#include <fstream>

using namespace std;

int compare(){
    string texts_folder = "../texts";
    vector<map<string, double>> features;
    
    for(int i=1;i<=4;i++){
        string path = texts_folder + to_string(i); 
        Extractor extractor(path);
        features.push_back(extractor.get_all_info());
    }   

    // to be continued....
}

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
