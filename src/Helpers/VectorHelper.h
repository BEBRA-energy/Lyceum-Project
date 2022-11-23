#include "../Classes/Extractor.h"

class VectorHelper {

public:
    static double dot_product(const vector<double> &a, const vector<double> &b);

    static double euclidian_norm(const vector<double> &a);

    static double cosine_similarity(const vector<double> &a, const vector<double> &b);
};