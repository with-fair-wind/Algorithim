/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

#include <cctype>
#include <map>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
private:
    map<char, int> m_map;

public:
    void initMap(string str, int row)
    {
        for (const char &c : str)
            m_map.insert(make_pair(c, row));
    }

    vector<string> findWords(vector<string> &words)
    {
        string s1 = "qwertyuiop", s2 = "asdfghjkl", s3 = "asdfghjkl";
        initMap(s1, 1);
        initMap(s2, 2);
        initMap(s3, 3);

        vector<string> res;
        for (const string &cur : words)
        {
            int row = m_map[tolower(cur[0])];
            bool isRight = true;
            for (const char &ch : cur)
            {
                if (m_map[tolower(ch)] != row)
                    isRight = false;
            }
            if (isRight)
                res.push_back(cur);
        }

        return res;
    }
};
// @lc code=end
