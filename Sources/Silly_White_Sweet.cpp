#include "Silly_White_Sweet.h"

using namespace std;

double getMedianOfArray(std::vector<int> &vec)
{
    sort(vec.begin(), vec.end());
    return (vec.size() % 2 == 0 ? double((vec[(vec.size() - 1) / 2] + vec[vec.size() / 2]) / 2.0) : double(vec[(vec.size() - 1) / 2]));
}