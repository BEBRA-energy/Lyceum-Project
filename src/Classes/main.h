#include "Extractor.h"

class Main {

private:

    vector<map<string, double>> features;


public:

    Main(string texts_folder);

    vector<map<string, double>> get_features();
};