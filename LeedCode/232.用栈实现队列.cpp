/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include <stack>

using namespace std;

// @lc code=start
class MyQueue
{
private:
    stack<int> m_stack1;
    stack<int> m_stack2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!m_stack1.empty())
        {
            m_stack2.push(m_stack1.top());
            m_stack1.pop();
        }
        m_stack1.push(x);
        while (!m_stack2.empty())
        {
            m_stack1.push(m_stack2.top());
            m_stack2.pop();
        }
    }

    int pop()
    {
        int res = m_stack1.top();
        m_stack1.pop();
        return res;
    }

    int peek()
    {
        return m_stack1.top();
    }

    bool empty()
    {
        return m_stack1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
