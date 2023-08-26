#include "Force_Recursion.h"

using namespace std;

void hanoi(int n)
{
    if (n > 0)
        hanoi(n, "left", "mid", "right");
}

void hanoi(int n, string from, string help, string to)
{
    if (n == 1)
        cout << "move 1 from " << from << " to " << to << endl;
    else
    {
        hanoi(n - 1, from, to, help);
        hanoi(1, from, help, to);
        hanoi(n - 1, help, from, to);
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

void printAllSubsequence_v1(string str)
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
        return res;
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

int winScoreDP(std::vector<int> &cards)
{
    if (cards.empty())
        return 0;
    vector<vector<int>> dpfirst(cards.size(), vector<int>(cards.size(), 0));
    vector<vector<int>> dplast(cards.size(), vector<int>(cards.size(), 0));
    for (size_t row = cards.size() - 1; row >= 0; row--)
    {
        dpfirst[row][row] = cards[row];
        for (size_t col = row + 1; col < cards.size(); col++)
        {
            dpfirst[row][col] = max(cards[row] + dplast[row + 1][col], cards[col] + dplast[row][col - 1]);
            dplast[row][col] = min(dpfirst[row + 1][col], dpfirst[row][col - 1]);
        }
    }
    return max(dpfirst[0][cards.size() - 1], dplast[0][cards.size() - 1]);
}

int NQueens_v1(int n)
{
    if (n < 1)
        return 0;
    vector<int> record(n); // 每一行上的索引(第几列)(0~n - 1)
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

int RobotWalk_v1(int N, int M, int P, int K)
{
    if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N)
        return 0;
    return walk(N, P, M, K);
}

int walk(int all, int end, int cur, int step)
{
    if (step == 0)
        return cur == end ? 1 : 0;
    if (cur == 1)
        return walk(all, end, cur + 1, step - 1);
    if (cur == all)
        return walk(all, end, cur - 1, step - 1);
    return walk(all, end, cur + 1, step - 1) + walk(all, end, cur - 1, step - 1);
}

int RobotWalk_v2(int N, int M, int P, int K)
{
    if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N)
        return 0;
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
    dp[0][P] = 1;
    for (int step = 1; step <= K; step++)
    {
        for (int cur = 1; cur <= N; cur++)
        {
            if (cur == 1)
                dp[step][cur] = dp[step - 1][cur + 1];
            else if (cur == N)
                dp[step][cur] = dp[step - 1][cur - 1];
            else
                dp[step][cur] = dp[step - 1][cur + 1] + dp[step - 1][cur - 1];
        }
    }
    return dp[K][M];
}

int coinsMin_v1(const vector<int> &vec, int aim)
{
    if (vec.empty() || aim == 0)
        return 0;
    return find(vec, 0, aim);
}

int find(const vector<int> &vec, int index, int aim)
{
    if (index == static_cast<int>(vec.size()))
        return aim == 0 ? 0 : -1;
    if (aim == 0)
        return 0;
    int res = -1;
    for (int num = 0; vec[index] * num <= aim; num++)
    {
        int next = find(vec, index + 1, aim - vec[index] * num);
        if (next != -1)
            res = res == -1 ? next + num : min(res, next + num);
    }
    return res;
}

int coinsMin_v2(const vector<int> &vec, int aim)
{
    if (vec.empty() || aim == 0)
        return 0;
    vector<vector<int>> dp(aim + 1, vector<int>(vec.size() + 1, 0));
    for (int row = 1; row <= aim; row++)
        for (int col = 0; col <= static_cast<int>(vec.size()); col++)
            dp[row][col] = -1;
    for (int col = vec.size() - 1; col >= 0; col--)
    {
        for (int row = aim; row > 0; row--)
        {
            for (int num = 0; vec[col] * num <= row; num++)
            {
                int next = dp[row - vec[col] * num][col + 1];
                if (next != -1)
                    dp[row][col] = dp[row][col] == -1 ? next + num : std::min(dp[row][col], next + num);
            }
        }
    }
    return dp[aim][0];
}

int HorseJump(int x, int y, int k)
{
    if (x < 0 || x > 8 || y < 0 || y > 9)
        return 0;
    if (k == 0)
        return (x == 0 && y == 0) ? 1 : 0;
    return HorseJump(x + 1, y + 2, k - 1) + HorseJump(x + 1, y - 2, k - 1) + HorseJump(x + 2, y + 1, k - 1) + HorseJump(x + 2, y - 1, k - 1) + HorseJump(x - 1, y + 2, k - 1) + HorseJump(x - 1, y - 2, k - 1) + HorseJump(x - 2, y + 1, k - 1) + HorseJump(x - 2, y - 1, k - 1);
}

int HorseJumpDP(int x, int y, int k)
{
    if (x < 0 || x > 8 || y < 0 || y > 9)
        return 0;
    vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(9, vector<int>(10, 0)));
    dp[0][0][0] = 1;
    for (int step = 1; step <= k; step++)
    {
        for (int r = 0; r <= 8; r++)
        {
            for (int c = 0; c <= 9; c++)
            {
                dp[step][r][c] += getVal(dp, r + 1, c + 2, step - 1);
                dp[step][r][c] += getVal(dp, r + 1, c - 2, step - 1);
                dp[step][r][c] += getVal(dp, r + 2, c + 1, step - 1);
                dp[step][r][c] += getVal(dp, r + 2, c - 1, step - 1);
                dp[step][r][c] += getVal(dp, r - 1, c + 2, step - 1);
                dp[step][r][c] += getVal(dp, r - 1, c - 2, step - 1);
                dp[step][r][c] += getVal(dp, r - 2, c + 1, step - 1);
                dp[step][r][c] += getVal(dp, r - 2, c - 1, step - 1);
            }
        }
    }
    return dp[k][x][y];
}

int getVal(const vector<vector<vector<int>>> &dp, int x, int y, int k)
{
    if (x < 0 || x > 8 || y < 0 || y > 9)
        return 0;
    return dp[k][x][y];
}

string BobDie(int n, int m, int i, int j, int k)
{
    long all = pow(4, k);
    long live = liveNum(n, m, i, j, k);
    long g = gcd(all, live);
    return to_string(live / g) + "/" + to_string(all / g);
}

long liveNum(int n, int m, int i, int j, int k)
{
    if (i < 0 || i == n || j < 0 || j == m)
        return 0;
    if (k == 0)
        return 1;
    return liveNum(n, m, i + 1, j, k - 1) + liveNum(n, m, i - 1, j, k - 1) + liveNum(n, m, i, j + 1, k - 1) + liveNum(n, m, i, j - 1, k - 1);
}

string BobDieDP(int n, int m, int i, int j, int k)
{
    long all = pow(4, k);
    vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n + 2, vector<int>(m + 2, 0)));
    for (int h = 0; h <= k; h++)
    {
        for (int r = 1; r <= n; r++)
        {
            for (int c = 1; c <= m; c++)
            {
                if (h == 0)
                    dp[h][r][c] = 1;
                else
                {
                    dp[h][r][c] += dp[h - 1][r + 1][c];
                    dp[h][r][c] += dp[h - 1][r - 1][c];
                    dp[h][r][c] += dp[h - 1][r][c + 1];
                    dp[h][r][c] += dp[h - 1][r][c - 1];
                }
            }
        }
    }
    long live = dp[k][i + 1][j + 1];
    long g = gcd(all, live);
    return to_string(live / g) + "/" + to_string(all / g);
}