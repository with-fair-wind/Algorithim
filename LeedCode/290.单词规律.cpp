/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<std::string> svec;
        istringstream iss(s);
        string word;
        // 以空格为分隔符将字符串划分为单词
        while (iss >> word)
            svec.push_back(word);

        if (svec.size() != pattern.length())
            return false;
        map<char, string> mapcmp;
        set<string> setstr;
        for (int i = 0; i < svec.size(); i++)
        {
            if (mapcmp.find(pattern[i]) == mapcmp.end())
            {
                mapcmp[pattern[i]] = svec[i];
                if (setstr.find(svec[i]) != setstr.end())
                    return false;
                setstr.insert(svec[i]);
            }
            else
            {
                if (mapcmp[pattern[i]] != svec[i])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
