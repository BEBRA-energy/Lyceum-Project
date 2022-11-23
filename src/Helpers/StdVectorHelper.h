#ifndef CMAKEPROJECT_STDVECTORHELPER_H
#define CMAKEPROJECT_STDVECTORHELPER_H

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class StdVectorHelper {

private:
    // Hide the constructor
    StdVectorHelper() = default;

public:

    template<class Type>
    static bool is_in_vector(const vector<Type> &vec, const Type &element);
};

template<class Type>
bool StdVectorHelper::is_in_vector(const vector<Type> &vec, const Type &element) {
    return find(vec.begin(), vec.end(), element) != vec.end();
}


#endif //CMAKEPROJECT_STDVECTORHELPER_H
