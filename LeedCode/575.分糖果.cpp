/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

#include <cmath>
#include <set>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        // set<int> setType;
        // int half = candyType.size() / 2;
        // for (const auto &candy : candyType)
        //     setType.insert(candy);
        // return setType.size() < half ? setType.size() : half;
        return min(set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
    }
};
// @lc code=end
