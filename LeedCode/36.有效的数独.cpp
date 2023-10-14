// @before-stub-for-debug-begin
#include "commoncppproblem36.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        map<char, vector<pair<int, int>>> mapShudu;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (mapShudu.find(board[i][j]) == mapShudu.end())
                    mapShudu[board[i][j]].push_back(make_pair(i, j));
                else
                {
                    for (const auto &pair : mapShudu[board[i][j]])
                    {
                        if (i == pair.first || j == pair.second || ((i / 3 == pair.first / 3) && (j / 3 == pair.second / 3)))
                            return false;
                    }
                    mapShudu[board[i][j]].push_back(make_pair(i, j));
                }
            }
        }
        return true;
    }
};
// @lc code=end
