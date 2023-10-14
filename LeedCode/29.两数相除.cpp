/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int divide(int a, int b)
    {
        try
        {
            if (b == 0)
                throw runtime_error(to_string(b));
        }
        catch (const runtime_error &e)
        {
            cerr << "divisor is " << e.what() << endl;
        }
        if (a == INT_MIN && b == INT_MIN)
            return 1;
        else if (b == INT_MIN)
            return 0;
        else if (a == INT_MIN)
        {
            if (b == -1)
                return INT_MAX;
            int res = div(add(a, 1), b);
            return add(res, div(minus(a, multi(b, res)), b));
        }
        else
            return div(a, b);
    }

    int div(int a, int b)
    {
        int x = isNeg(a) ? negNum(a) : a;
        int y = isNeg(b) ? negNum(b) : b;
        int res = 0;
        for (int i = 30; i >= 0; i = minus(i, 1))
        {
            if ((x >> i) >= y)
            {
                res |= (1 << i);
                x = minus(x, (y << i));
            }
        }
        return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
    }

    bool isNeg(int num) { return (num >> 31) & 1; }
    int negNum(int num) { return add(~num, 1); }
    int minus(int a, int b) { return add(a, negNum(b)); }

    int add(int a, int b)
    {
        int res = a;
        while (b)
        {
            res = a ^ b;
            b = (a & b) << 1;
            a = res;
        }
        return res;
    }

    int multi(int a, int b)
    {
        int res = 0;
        unsigned int cur = static_cast<unsigned int>(b);
        while (cur)
        {
            if (cur & 1)
                res = add(res, a);
            a <<= 1;
            cur >>= 1;
        }
        return res;
    }
};
// @lc code=end
