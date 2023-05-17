#include "Struct.h"

using namespace std;

int BitMap::getMax(int a, int b)
{
    int sa = sign(a), sb = sign(b), sc = sign(a - b);
    int difSab = sa ^ sb;
    int sameSab = flip(difSab);
    int resA = difSab * sa + sameSab * sc;
    int resB = flip(resA);
    return resA * a + resB * b;
}

int BitMap::add(int a, int b)
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

int BitMap::multi(int a, int b)
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

int BitMap::div(int a, int b)
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

int BitMap::divide(int a, int b)
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
        int res = div(add(a, 1), b);
        return add(res, div(minus(a, multi(b, res)), b));
    }
    else
        return div(a, b);
}

int Islandcounts(std::vector<std::vector<int>> &grid)
{
    int rows = grid.size();
    if (rows == 0)
        return 0;
    int cols = grid[0].size();
    if (cols == 0)
        return 0;
    int res = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                infect(grid, i, j, rows, cols);
                res++;
            }
        }
    }
    return res;
}

void infect(std::vector<std::vector<int>> &grid, int i, int j, int rows, int columns)
{
    if (i < 0 || i >= rows || j < 0 || j >= columns || grid[i][j] != 1)
        return;
    grid[i][j] = 2;
    infect(grid, i + 1, j, rows, columns);
    infect(grid, i - 1, j, rows, columns);
    infect(grid, i, j + 1, rows, columns);
    infect(grid, i, j - 1, rows, columns);
}

int KMP(const string &s, const string &m)
{
    if (s.length() < 1 || m.length() < 1 || s.length() < m.length())
        return -1;
    size_t *nextArr = new size_t[m.length()];
    getNextArray(nextArr, m); // (索引i前)前缀和后缀相等的最大长度(不包含整体)
    size_t s_index = 0, m_index = 0;
    while (s_index < s.length() && m_index < m.length())
    {
        if (s[s_index] == m[m_index])
        {
            s_index++;
            m_index++;
        }
        else if (m_index == 0) // nextArr[m_index]==-1
            s_index++;
        else
            m_index = nextArr[m_index];
    }
    delete[] nextArr;
    return m_index == m.length() ? s_index - m_index : -1;
}

void getNextArray(size_t *nextArr, const string &m)
{
    if (m.length() == 1)
    {
        nextArr[0] = -1;
        return;
    }
    nextArr[0] = -1;
    nextArr[1] = 0;
    size_t index = 2;
    size_t cn = 0;
    while (index < m.length())
    {
        if (m[index - 1] == m[cn])
            nextArr[index++] = ++cn;
        else if (cn > 0)
            cn = nextArr[cn];
        else
            nextArr[index++] = 0;
    }
    return;
}

int Manacher(const string &str)
{
    if (str.length() < 1)
        return 0;
    string fixStr = ManacherString(str);
    int MaxLen = INT_MIN;
    int maxPalindRadius[fixStr.length()];
    // 回文半径包括中间的那个，比如bab,回文半径是2
    // R代表之前所有扩的位置中所到达所有最右回文最右边界的下一个位置，就是如果发现i对应的最长回文半径更大后，就更新R这个边界,R只会递增
    // R递增Center就更新(右边界突破了就更新)(同步更新)
    int R = -1, Center = -1;
    for (int i = 0; i < static_cast<int>(fixStr.length()); i++)
    {
        maxPalindRadius[i] = R > i ? min(maxPalindRadius[2 * Center - i], R - i) : 1;
        while (i + maxPalindRadius[i] < static_cast<int>(fixStr.length()) && i - maxPalindRadius[i] > -1)
        {
            if (fixStr[i + maxPalindRadius[i]] == fixStr[i - maxPalindRadius[i]])
                maxPalindRadius[i]++;
            else
                break;
        }
        if (i + maxPalindRadius[i] > R)
        {
            R = i + maxPalindRadius[i];
            Center = i;
        }
        // 以上才是重点,求出每个索引对应的最长回文子串长度
        MaxLen = max(MaxLen, maxPalindRadius[i]);
    }
    return MaxLen - 1;
}

string ManacherString(const string &str)
{
    string output;
    for (char c : str)
    {
        output += '#';
        output += c;
    }
    output += '#';
    return output;
}

void getMaxWindow(vector<int> &resArr, const vector<int> &arr, int WinSize)
{
    if (arr.size() == 0 || WinSize > static_cast<int>(arr.size()) || WinSize < 1)
        return;
    deque<int> qmax;
    for (int i = 0; i < static_cast<int>(arr.size()); i++)
    {
        while (!qmax.empty() && arr[qmax.back()] <= arr[i])
            qmax.pop_back();
        qmax.push_back(i);
        if (i - WinSize == qmax.front())
            qmax.pop_front();
        if (i >= WinSize - 1)
            resArr.push_back(arr[qmax.front()]);
    }
}

void getNearLess(vector<pair<int, int>> &res, const vector<int> &arr)
{
    stack<list<int>> LessStack; // 从小到大
    for (int i = 0; i < static_cast<int>(arr.size()); i++)
    {
        while (!LessStack.empty() && arr[LessStack.top().front()] > arr[i])
        {
            list<int> SameList = LessStack.top();
            LessStack.pop();
            for (const int &tmp : SameList)
                res[tmp] = LessStack.empty() ? make_pair(-1, i) : make_pair(LessStack.top().back(), i);
        }
        if (!LessStack.empty() && arr[LessStack.top().front()] == arr[i])
            LessStack.top().push_back(i);
        else
            LessStack.push(list<int>{i});
    }
    while (!LessStack.empty())
    {
        list<int> SameList = LessStack.top();
        LessStack.pop();
        for (const int &tmp : SameList)
            res[tmp] = LessStack.empty() ? make_pair(-1, -1) : make_pair(LessStack.top().back(), -1);
    }
}

int MaxTargetA(const std::vector<int> &arr)
{
    int max = INT_MIN;
    vector<int> Sum = arr;
    for (int i = 1; i < static_cast<int>(Sum.size()); i++)
        Sum[i] = Sum[i - 1] + arr[i];
    stack<list<int>> LessStack;
    for (int i = 0; i < static_cast<int>(arr.size()); i++)
    {
        while (!LessStack.empty() && arr[LessStack.top().front()] > arr[i])
        {
            list<int> SameList = LessStack.top();
            LessStack.pop();
            for (const int &tmp : SameList)
                max = std::max(max, LessStack.empty() ? Sum[i - 1] * arr[tmp] : (Sum[i - 1] - Sum[LessStack.top().back()]) * arr[tmp]);
        }
        if (!LessStack.empty() && arr[LessStack.top().front()] == arr[i])
            LessStack.top().push_back(i);
        else
            LessStack.push(list<int>{i});
    }
    while (!LessStack.empty())
    {
        list<int> SameList = LessStack.top();
        LessStack.pop();
        for (const int &tmp : SameList)
            max = std::max(max, LessStack.empty() ? Sum[arr.size() - 1] * arr[tmp] : (Sum[arr.size() - 1] - Sum[LessStack.top().back()]) * arr[tmp]);
    }
    return max;
}