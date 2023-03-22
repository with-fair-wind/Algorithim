#include "TrieTree_Greedy.h"

using namespace std;

string lowestString(std::vector<string> &strs)
{
    if (strs.empty())
        return "";
    sort(strs.begin(), strs.end(), [](string &s1, string &s2)
         { return strcmp((s1 + s2).c_str(), (s2 + s1).c_str()); });
    string result = "";
    for (const auto &str : strs)
        result += str;
    return result;
}

int lessMoney(std::vector<int> &vec)
{
    priority_queue<int, vector<int>, greater<int>> pQ;
    int result = 0;
    for (auto &num : vec)
        pQ.push(num);
    while (pQ.size() > 1)
    {
        int n1 = pQ.top();
        pQ.pop();
        int n2 = pQ.top();
        pQ.pop();
        result += (n1 + n2);
        pQ.push(n1 + n2);
    }
    return result;
}

struct Cmp_program
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

#define PQUEUE
int bestArrange(vector<pair<int, int>> &programs, int start)
{
    int result = 0;
#ifdef PQUEUE
    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp_program> pQ;
    for (auto program : programs)
        pQ.push(program);
    for (size_t i = 0; i < programs.size(); i++)
    {
        if (start < pQ.top().first)
        {
            start = pQ.top().second;
            pQ.pop();
            result++;
        }
    }
#endif

#ifdef ARRSORT
    sort(programs.begin(), programs.end(), [](const pair<int, int> &p1, const pair<int, int> &p2)
         { return p1.second < p2.second; });
    for (auto &pro : programs)
    {
        if (start < pro.first)
        {
            start = pro.second;
            result++;
        }
    }
#endif
    return result;
}

struct Cmp_program_Capital
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.first > p2.first;
    }
};

struct Cmp_program_Profits
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second < p2.second;
    }
};

int findMaximizedCapital(int frequency, int start, vector<pair<int, int>> programs)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp_program_Capital> CapitalQue;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp_program_Profits> ProfitsQue;

    for (auto &pro : programs)
        CapitalQue.push(pro);

    for (int i = 0; i < frequency; i++)
    {
        while (!CapitalQue.empty() && CapitalQue.top().first <= start)
        {
            ProfitsQue.push(CapitalQue.top());
            CapitalQue.pop();
        }
        if (ProfitsQue.empty())
            return start;
        start += ProfitsQue.top().second;
        ProfitsQue.pop();
    }
    return start;
}

double getMedian(vector<int> &vec)
{
    priority_queue<int, vector<int>, greater<int>> smallQue;
    priority_queue<int, vector<int>> bigQue;
    for (auto &cur : vec)
    {
        // 必须有判断，否则单纯把小根堆移动至大根堆，在最后一个数进来时，会出问题，没有判断，最后一个数无法控制是多少
        if (smallQue.empty() || cur >= smallQue.top())
            smallQue.push(cur);
        else
            bigQue.push(cur);
        if (abs(smallQue.size() - bigQue.size() > 1))
        {
            if (smallQue.size() > bigQue.size())
            {
                bigQue.push(smallQue.top());
                smallQue.pop();
            }
            else
            {
                smallQue.push(bigQue.top());
                bigQue.pop();
            }
        }
    }
    return vec.size() % 2 == 0 ? double((smallQue.top() + bigQue.top()) / 2.0) : double(smallQue.size() > bigQue.size() ? smallQue.top() : bigQue.top());
}