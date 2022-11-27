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
    double similarity = dot_product(a, b) / (euclidian_norm(a) * euclidian_norm(b));
    return similarity;
}

double VectorHelper::RMSE(const vector<double> &a, const vector<double> &b){
    int length = a.size();

    vector<double> diffs;
    // получение разностей
    for(int i = 0;i<length;i++){
        diffs.push_back(a[i]-b[i]);
    }

    long double total_sum = 0;
    for(int i =0;i<length;i++){
        total_sum += diffs[i]*diffs[i];
    }

    return 1.-sqrtl(total_sum/length);
}