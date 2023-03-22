#ifndef __TRIETREE_GREEDY_H__
#define __TRIETREE_GREEDY_H__

#include "Fun.h"
#include <algorithm>
#include <cstring>
#include <memory>
#include <queue>
#include <unordered_map>

struct TrieNode
{
    int pass;
    int end;
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;

    TrieNode() : pass(0), end(0) {}
};

class Trie
{
private:
    std::shared_ptr<TrieNode> root;

public:
    Trie() : root(std::make_shared<TrieNode>()) {}

    void insertStr(const std::string &word)
    {
        std::shared_ptr<TrieNode> node = root;
        for (char ch : word)
        {
            if (node->children.count(ch) == 0)
            {
                node->children[ch] = std::make_shared<TrieNode>();
            }
            node = node->children[ch];
            node->pass++;
        }
        node->end++;
    }

    int searchStr(const std::string &word)
    {
        std::shared_ptr<TrieNode> node = root;
        for (char ch : word)
        {
            if (node->children.count(ch) == 0)
                return 0;
            node = node->children[ch];
        }
        return node->end;
    }

    int prefixNum(const std::string &word)
    {
        std::shared_ptr<TrieNode> node = root;
        for (char ch : word)
        {
            if (node->children.count(ch) == 0)
                return 0;
            node = node->children[ch];
        }
        return node->pass;
    }

    void deleteChildren(std::shared_ptr<TrieNode> node)
    {
        if (!node)
            return;
        // 递归地删除子节点
        for (auto &child : node->children)
        {
            deleteChildren(child.second);
            child.second.reset();
        }
        // 清空子节点映射
        node->children.clear();
    }

    void removeStr(const std::string &word)
    {
        if (searchStr(word))
        {
            std::shared_ptr<TrieNode> node = root;
            for (auto &ch : word)
            {
                if (--node->children[ch]->pass == 0)
                {
                    deleteChildren(node->children[ch]);
                    node->children.erase(ch);
                    return;
                }
                node = node->children[ch];
            }
            node->end--;
        }
    }
};

// 合并数组中的字符串使最后结果的字典序最小
std::string lowestString(std::vector<std::string> &strs);
// 如何分金条钱最少
int lessMoney(std::vector<int> &vec);
// 最好的安排一天的会议时间使得一天中能够进行的会议次数最大，start为一天中最初可以安排的时间，pair中first为会议开始时间，second为会议结束时间
int bestArrange(std::vector<std::pair<int, int>> &programs, int start);
// 最大化收益, pair中first为花费，second为收益, start为启动资金， frequency为最多完成项目的次数
int findMaximizedCapital(int frequency, int start, std::vector<std::pair<int, int>> programs);
// 快速寻找中位数
double getMedian(std::vector<int> &vec);
#endif
