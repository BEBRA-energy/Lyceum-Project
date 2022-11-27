#ifndef CMAKEPROJECT_COMPARATOR_H
#define CMAKEPROJECT_COMPARATOR_H

#include <string>
#include <vector>
#include <map>

#include "Extractor.h"
#include "../Helpers/VectorHelper.h"

using namespace std;

class Comparator {

private:
    string texts_folder;
    vector<string> files;
    int files_count;

public:

    Comparator(const string &text_folder, const vector<string> &files);

    vector<map<string, double>> calculate_features();

    // возвращает вектор матриц значений разных метрик
    vector<vector<vector<double>>> compare();

    vector<vector<double>> calculate_features_values();

    vector<vector<double>> scale_features(vector<vector<double>> features);    
};


#endif //CMAKEPROJECT_COMPARATOR_H
