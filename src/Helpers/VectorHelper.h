#ifndef CMAKEPROJECT_VECTORHELPER_H
#define CMAKEPROJECT_VECTORHELPER_H

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class VectorHelper {

private:
    // Hide the constructor
    VectorHelper() = default;

public:

    template<class Type>
    static bool is_in_vector(const vector<Type> &vec, const Type &element);
};

template<class Type>
bool VectorHelper::is_in_vector(const vector<Type> &vec, const Type &element) {
    return find(vec.begin(), vec.end(), element) != vec.end();
}


#endif //CMAKEPROJECT_VECTORHELPER_H
