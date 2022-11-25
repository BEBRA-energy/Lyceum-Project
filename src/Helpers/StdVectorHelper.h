#ifndef CMAKEPROJECT_STDVECTORHELPER_H
#define CMAKEPROJECT_STDVECTORHELPER_H

#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class StdVectorHelper {

private:
    // Hide the constructor
    StdVectorHelper() = default;

public:

    template<class Type>
    static bool is_in_vector(const vector<Type> &vec, const Type &element);

    template<class Type1, class Type2>
    static vector<Type1> get_map_values(const map<Type2, Type1> &dict);
};

template<class Type>
bool StdVectorHelper::is_in_vector(const vector<Type> &vec, const Type &element) {
    return find(vec.begin(), vec.end(), element) != vec.end();
}

template<class Type, class SubType>
vector<Type> StdVectorHelper::get_map_values(const map<SubType, Type> &dict) {
    vector<Type> result;
    for (const auto &[key, value]: dict)
        result.push_back(value);
    return result;
}

#endif //CMAKEPROJECT_STDVECTORHELPER_H