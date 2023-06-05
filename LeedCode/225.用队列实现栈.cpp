/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include <queue>

using namespace std;

// @lc code=start
class MyStack
{
private:
    queue<int> m_queue1, m_queue2;

public:
    MyStack()
    {
        m_queue1 = queue<int>();
        m_queue2 = queue<int>();
    }

    void push(int x)
    {
        while (!m_queue1.empty())
        {
            m_queue2.push(m_queue1.front());
            m_queue1.pop();
        }
        m_queue1.push(x);
        while (!m_queue2.empty())
        {
            m_queue1.push(m_queue2.front());
            m_queue2.pop();
        }
    }

    int pop()
    {
        int res = m_queue1.front();
        m_queue1.pop();
        return res;
    }

    int top()
    {
        return m_queue1.front();
    }

    bool empty()
    {
        return m_queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
