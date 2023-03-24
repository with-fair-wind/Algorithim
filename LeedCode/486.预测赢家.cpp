/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        if (nums.empty())
            return false;
        return goFirst(nums, 0, nums.size() - 1) >= goLast(nums, 0, nums.size() - 1);
    }

    int goFirst(vector<int> &cards, int head, int last)
    {
        if (head == last)
            return cards[head];
        // 先拿了一张后，后面我就是在last - head范围上后手拿牌了
        return max(cards[head] + goLast(cards, head + 1, last), cards[last] + goLast(cards, head, last - 1));
    }

    int goLast(vector<int> &cards, int head, int last)
    {
        if (head == last)
            return 0;
        return min(goFirst(cards, head + 1, last), goFirst(cards, head, last - 1));
    }
};
// @lc code=end
