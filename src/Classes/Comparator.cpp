#include "Comparator.h"

Comparator::Comparator(const string &text_folder, const vector<string> &files) {
    this->texts_folder = text_folder;
    this->files = files;
    this->files_count = int(files.size());
}

vector<map<string, double>> Comparator::calculate_features() {
    vector<map<string, double>> features;
    for (const string &file: this->files) {
        string path = this->texts_folder + "/" + file;
        Extractor extractor(path);
        features.push_back(extractor.get_all_info());
    }
    return features;
}

vector<vector<double>> Comparator::calculate_features_values() {
    vector<vector<double>> result;
    vector<map<string, double>> features = this->calculate_features();
    result.reserve(features.size());
    for (const map<string, double> &text_feature: features) {
        result.push_back(StdVectorHelper::get_map_values(text_feature));
    }
    return result;
}

vector<vector<double>> Comparator::scale_features(vector<vector<double>> features){

    vector<vector<double>> values_only = features;
    for(int col = 0; col< values_only[0].size(); col++){
        double max_feature = values_only[0][col];
        for(int row = 0; row<values_only.size(); row++){
            max_feature = max(values_only[row][col], max_feature);
        }

        if(max_feature==0.0)
            continue;

        for(int row = 0; row<values_only.size(); row++){
            values_only[row][col]/=max_feature; 
        }
    }
    return values_only;
}

vector<vector<vector<double>>> Comparator::compare() {
    vector<vector<double>> result_cosine(this->files_count, vector<double>(this->files_count));
    vector<vector<double>> result_rmse(this->files_count, vector<double>(this->files_count));

    vector<vector<double>> features = scale_features(calculate_features_values());

    for (int i = 0; i < this->files_count; i++) {
        for (int j = 0; j < this->files_count; j++) {
            vector<double> first_file = features[i];
            vector<double> second_file = features[j];
            result_cosine[i][j] = VectorHelper::cosine_similarity(first_file, second_file);
            result_rmse[i][j] = VectorHelper::RMSE(first_file, second_file);
        }
    }

    vector<vector<vector<double>>> result = {result_cosine, result_rmse};
    return result;
}
