#include "Force_Recursion.h"

using namespace std;

void hanoi(int n)
{
    if (n > 0)
        hanoi(n, n, "left", "mid", "right");
}

void hanoi(int n, int real, string from, string help, string to)
{
    if (n == 1)
        cout << "move " << real << " from " << from << " to " << to << endl;
    else
    {
        hanoi(n - 1, real - 1, from, to, help);
        hanoi(1, real, from, help, to);
        hanoi(n - 1, n - 1, help, from, to);
    }
}

void printAllSubsequence_v2(const string &str)
{
    vector<char> chs(str.begin(), str.end());
    process(chs, 0);
}

void process(vector<char> &chs, size_t i)
{
    // 如果i超过范围了，那前面[0~i-1]已经是一种结果了，直接打印就好了
    if (i == chs.size())
    {
        for (char c : chs)
        {
            if (c != '\0')
                cout << c;
        }
        cout << endl;
        return;
    }

    process(chs, i + 1); // 考虑chs[i]的值，打印后续从i+1开始的子序列
    char tmp = chs[i];
    chs[i] = '\0';
    process(chs, i + 1); // 不考虑chs[i]的值，打印后续从i+1开始的子序列
    chs[i] = tmp;
}

void printAllSubsquence_v1(string str)
{
    string output;
    func_v1(str, output);
}

void func_v1(string str, string output)
{
    if (str.empty())
    {
        cout << output << endl;
        return;
    }
    func_v1(str.substr(1), output);
    func_v1(str.substr(1), output + str[0]);
}

vector<string> Permutation(string str)
{
    if (str.empty())
        return vector<string>();
    vector<string> result;
    func_v2(str, 0, result);
    return result;
}

void func_v2(string str, size_t i, vector<string> &res)
{
    if (i == str.length())
        res.push_back(str);
    vector<int> repeat(26);
    for (size_t j = i; j < str.length(); j++)
    {
        if (repeat[str[j] - 'a'] == 0)
        {
            repeat[str[j] - 'a'] = 1;
            swap_str(str, i, j);
            func_v2(str, i + 1, res);
            swap_str(str, i, j);
        }
    }
}

void swap_str(std::string &str, size_t i, size_t j)
{
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
        return;
    int num = getAndRemoveLastElement(stack);
    reverseStack(stack);
    stack.push(num);
}

int getAndRemoveLastElement(stack<int> &stack)
{
    int top = stack.top();
    stack.pop();
    if (stack.empty())
        return top;
    int res = getAndRemoveLastElement(stack);
    stack.push(top);
    return res;
}

int ConvertToLetterString(std::string numStr)
{
    if (numStr.empty())
        return 0;
    return func_v3(numStr, 0);
}

int func_v3(std::string numStr, size_t i)
{
    if (i == numStr.length())
        return 1;
    if (numStr[i] == '0')
        return 0;
    if (numStr[i] == '1')
    {
        int res = func_v3(numStr, i + 1);
        if (i + 1 < numStr.length()) // 保证第i+1位是有效的
            res += func_v3(numStr, i + 2);
    }

    if (numStr[i] == '2')
    {
        int res = func_v3(numStr, i + 1);
        if (i + 1 < numStr.length() && numStr[i + 1] <= '6' && numStr[i + 1] >= '0')
            res += func_v3(numStr, i + 2);
        return res;
    }
    return func_v3(numStr, i + 1);
}

int maxValue(int *weights, int *values, int full, int bag)
{
    return func_v4(weights, values, full, bag, 0, 0, 0);
}

int func_v4(int *weights, int *values, int full, int bag, int i, int alreadyWeight, int alreadyValues)
{
    // 如果前面确定的重量超重了，那么返回0
    if (alreadyWeight > bag)
        return 0;
    // 如果前面已经把所有物品全装了，返回已经有的价值
    if (i == full)
        return alreadyValues;
    // 我装i个后和不装第i个(已经确定了)从第i+1开始得到的最大价值取最大值
    return std::max(func_v4(weights, values, full, bag, i + 1, alreadyWeight, alreadyValues),
                    func_v4(weights, values, full, bag, i + 1, alreadyWeight + weights[i], alreadyValues + values[i]));
}

int winScore(vector<int> &cards)
{
    if (cards.empty())
        return 0;
    return std::max(goFirst(cards, 0, cards.size() - 1), goLast(cards, 0, cards.size() - 1));
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

int NQueens_v1(int n)
{
    if (n < 1)
        return 0;
    vector<int> record; // 每一行上的索引(第几列)(0~n - 1)
    return func_v5(record, 0, n);
}

int func_v5(vector<int> &record, int i, int n)
{
    if (i == n)
        return 1;
    int res = 0;
    for (int j = 0; j < n; j++) // j为可能放到第几列
    {
        if (isValid(record, i, j))
        {
            record[i] = j;
            res += func_v5(record, i + 1, n);
        }
    }
    return res;
}

bool isValid(vector<int> &record, int i, int j)
{
    for (int k = 0; k < i; k++) // k为前面的0 - i-1行
    {
        if (j == record[k] || abs(record[k] - j) == abs(k - i))
            return false;
    }
    return true;
}

int NQueens_v2(int n)
{
    if (n < 1 || n > 32)
        return 0;
    int upperLim = n == 32 ? -1 : ((1 << n) - 1);
    return func_v6(upperLim, 0, 0, 0);
}

int func_v6(int upperLim, int colLim, int leftDiaLim, int rightDiaLim)
{
    if (colLim == upperLim)
        return 1;
    int pos = 0, res = 0, mostRight = 0;
    pos = upperLim & (~(colLim | leftDiaLim | rightDiaLim));
    while (pos)
    {
        mostRight = pos & (~pos + 1);
        pos -= mostRight;
        res += func_v6(upperLim, colLim | mostRight, (leftDiaLim | mostRight) << 1, (rightDiaLim | mostRight) >> 1);
    }
    return res;
}