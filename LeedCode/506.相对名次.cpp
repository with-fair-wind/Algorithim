/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

#include <map>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        map<int, int> mapScores;
        vector<string> res(score.size());
        for (int i = 0; i < score.size(); i++)
            mapScores.insert(make_pair(score[i], i));
        int grade = score.size();
        map<int, string> maptmp{{1, "Gold Medal"}, {2, "Silver Medal"}, {3, "Bronze Medal"}};
        for (auto iter = mapScores.begin(); iter != mapScores.end(); iter++)
        {
            if (maptmp.find(grade) == maptmp.end())
                res[(*iter).second] = to_string(grade);
            else
                res[(*iter).second] = maptmp[grade];
            grade--;
        }
        return res;
    }
};
// @lc code=end
