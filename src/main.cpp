#define LOCAL_DEBUG

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
    
    vector<vector<double>> values_only;
    for(map<string, double> text_features: features){
        vector<double> text_values; 
        for(auto value: text_features)
            text_values.push_back(value.second);
        values_only.push_back(text_values);
    }

    int num_texts = values_only.size();
    ofstream fout("output.txt");
    //vector<vector<double>> similarities;
    for(int i =1;i<=num_texts;i++){
        vector<double> i_vector_similarities;
        for(int j = 1;j<=num_texts;j++){
            vector<double> text1 = values_only[i];
            vector<double> text2 = values_only[j];
            //i_vector_similarities.push_back(VectorHelper::cosine_similarity(text1, text2));
            fout<<"text "<<i<<" and "<<j<<VectorHelper::cosine_similarity(text1, text2)<<endl;
        }
        //similarities.push_back(i_vector_similarities);
    } 
   f 
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
