#include "Classes/Extractor.h"
#include "Helpers/VectorHelper.h"

#include <iostream>

using namespace std;

int main() {
    string texts_folder = "../texts";
    vector<map<string, double>> features;
    
    for(int i=1;i<=4;i++){
        string path = texts_folder + to_string(i); 
        Extractor extractor(path);
        features.push_back(extractor.get_all_info());
    }

     

    return 0;
}
