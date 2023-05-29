// @before-stub-for-debug-begin
#include "commoncppproblem14.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include <algorithm>
#include <cstring>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
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

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        return ansV2(strs);
    }

    string ansV1(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        Trie tire;
        string lessStr = strs[0];
        for (const auto &str : strs)
        {
            tire.insertStr(str);
            lessStr = lessStr.length() <= str.length() ? lessStr : str;
        }
        if (tire.prefixNum(lessStr.substr(0, 1)) != strs.size())
            return "";
        string res;
        for (int i = 0; i < lessStr.size(); i++)
        {
            if (tire.prefixNum(lessStr.substr(0, i + 1)) == strs.size())
                res = lessStr.substr(0, i + 1);
            else
                break;
        }
        return res;
    }

    string ansV2(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        return process(strs, 0, strs[0]);
    }

    string process(vector<string> &strs, int index, string nowStr)
    {
        if (index == strs.size() - 1)
            return commonPrefix(nowStr, strs[index]);
        string cur = commonPrefix(nowStr, strs[index]);
        string temp = process(strs, index + 1, cur);
        return commonPrefix(temp, cur);
    }

    string commonPrefix(const string &str1, const string &str2)
    {
        string result;
        int n1 = str1.length();
        int n2 = str2.length();

        // 遍历字符串，直到较短的字符串结束或者字符不匹配
        for (int i = 0; i < n1 && i < n2; i++)
        {
            if (str1[i] != str2[i])
                break;
            result += str1[i];
        }
        return result;
    }
};
// @lc code=end
