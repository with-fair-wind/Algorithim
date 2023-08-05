// @before-stub-for-debug-begin
#include "commoncppproblem703.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class KthLargest
{
public:
    KthLargest(int k, vector<int> &nums) : m_k(k)
    {
        for (const int &cur : nums)
            add(cur);
    }

    int add(int val)
    {
        m_que.push(val);
        if (m_que.size() > m_k)
            m_que.pop();
        return m_que.top();
    }

private:
    int m_k;
    priority_queue<int, vector<int>, greater<int>> m_que;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
