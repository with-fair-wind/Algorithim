/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

#include <set>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        int result = 0;
        vector<int> help;
        set<string> strset{"C", "D", "+"};
        for (int i = 0; i < operations.size(); i++)
        {
            if (strset.find(operations[i]) == strset.end())
                help.push_back(stoi(operations[i]));
            else
            {
                if (operations[i] == "C")
                    help.erase(help.end() - 1);
                else if (operations[i] == "D")
                    help.push_back(*(help.rbegin()) * 2);
                else
                    help.push_back(help[help.size() - 1] + help[help.size() - 2]);
            }
        }
        for (const int &cur : help)
            result += cur;
        return result;
    }
};
// @lc code=end
