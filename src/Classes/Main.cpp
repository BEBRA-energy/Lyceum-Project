#include "Main.h"

Main::Main(string texts_folder) {
    for (int i = 1; i <= 4; i++) {
        string path = texts_folder + to_string(i) + ".txt";
        Extractor extractor(path);
        this->features.push_back(extractor.get_all_info());
    }
}

vector<map<string, double>> Main::get_features() {
    return this->features;
}
