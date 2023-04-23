#include "Silly_White_Sweet.h"

using namespace std;

double getMedian_easy(std::vector<int> &vec)
{
    sort(vec.begin(), vec.end());
    return (vec.size() % 2 == 0 ? double((vec[(vec.size() - 1) / 2] + vec[vec.size() / 2]) / 2.0) : double(vec[(vec.size() - 1) / 2]));
}

void getNearLess_easy(vector<pair<int, int>> &res, const vector<int> &arr)
{
    for (int i = 0; i < static_cast<int>(arr.size()); i++)
    {
        int LeftIndex = -1, RightIndex = -1;
        int cur = i - 1;
        while (cur >= 0)
        {
            if (arr[cur] < arr[i])
            {
                LeftIndex = cur;
                break;
            }
            cur--;
        }
        cur = i + 1;
        while (cur < static_cast<int>(arr.size()))
        {
            if (arr[cur] < arr[i])
            {
                RightIndex = cur;
                break;
            }
            cur++;
        }
        res[i] = make_pair(LeftIndex, RightIndex);
    }
}

#define LESSSTACK // LESSSTACK, FORCE
int MaxTargetA_easy(const std::vector<int> &arr)
{
    int max = INT_MIN;
#ifdef LESSSTACK
    vector<int> Sum = arr;
    for (int i = 1; i < static_cast<int>(Sum.size()); i++)
        Sum[i] = Sum[i - 1] + arr[i];
    for (int i = 0; i < static_cast<int>(arr.size()); i++)
    {
        int LeftIndex = -1, RightIndex = -1;
        int cur = i - 1;
        while (cur >= 0)
        {
            if (arr[cur] < arr[i])
            {
                LeftIndex = cur;
                break;
            }
            cur--;
        }
        cur = i + 1;
        while (cur < static_cast<int>(arr.size()))
        {
            if (arr[cur] < arr[i])
            {
                RightIndex = cur;
                break;
            }
            cur++;
        }
        if (LeftIndex == -1 && RightIndex == -1)
            max = std::max(max, Sum[arr.size() - 1] * arr[i]);
        else if (LeftIndex == -1)
            max = std::max(max, Sum[RightIndex - 1] * arr[i]);
        else if (RightIndex == -1)
            max = std::max(max, (Sum[arr.size() - 1] - Sum[LeftIndex]) * arr[i]);
        else
            max = std::max(max, (Sum[RightIndex - 1] - Sum[LeftIndex]) * arr[i]);
    }
#endif

#ifdef FORCE
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int sum = 0;
            int minNum = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
                minNum = std::min(minNum, arr[k]);
            }
            // 所有子数组
            max = std::max(max, sum * minNum);
        }
    }
#endif
    return max;
}