#include "VectorHelper.h"

double VectorHelper::dot_product(const vector<double> &a, const vector<double> &b) {
    double res = 0;
    for (int i = 0; i < a.size(); i++) {
        res += a[i] * b[i];
    }
    return res;
}

double VectorHelper::euclidian_norm(const vector<double> &a) {
    double res = 0;
    for (int i = 0; i < a.size(); i++) {
        res += a[i] * a[i];
    }
    return sqrt(res);
}

double VectorHelper::cosine_similarity(const vector<double> &a, const vector<double> &b) {
    double similarity = dot_product(a, b) / euclidian_norm(a) * euclidian_norm(b);
    return similarity;
}
