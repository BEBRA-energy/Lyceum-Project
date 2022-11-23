#include "Classes/Extractor.h"
<<<<<<< HEAD
#include "Helpers/VectorHelper.h"

#include <iostream>
=======
#include <fstream>
>>>>>>> b5a1467c3b89d8fd2a0da14f41cde872215bf0ec

using namespace std;

int main() {
<<<<<<< HEAD
    string texts_folder = "../texts";
    vector<map<string, double>> features;
    
    for(int i=1;i<=4;i++){
        string path = texts_folder + to_string(i); 
        Extractor extractor(path);
        features.push_back(extractor.get_all_info());
    }

     
=======
    setlocale(LC_ALL, "ru");

    Extractor ex("../texts/1.txt");

    auto res = ex.get_sentences();

    ofstream fout("output.txt");

    fout << res.size() << '\n';

    for (const auto &el: res)
        fout << el << '\n';
>>>>>>> b5a1467c3b89d8fd2a0da14f41cde872215bf0ec

    return 0;
}
