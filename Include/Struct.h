#include "Fun.h"
#include <stack>
#include <unordered_map>

// RandomPool结构
// 三个方法都是O(1)的时间复杂度
// insert(key):将某个key加入到该结构，做到不重复加入
// delete(key):将原本在结构中的某个key移除
// getRandom(): 等概率随机返回结构中的任何一个key
template <typename T>
class RandomPool
{
private:
    std::unordered_map<T, int> m_KeyIndexMap;
    std::unordered_map<int, T> m_IndexKeyMap;
    int m_size;
    std::mt19937 m_rng;

public:
    RandomPool() : m_KeyIndexMap(), m_IndexKeyMap(), m_size(0), m_rng(std::time(0)) {}
    void insert_Key(T key)
    {
        if (m_KeyIndexMap.find(key) == m_KeyIndexMap.end())
        {
            m_KeyIndexMap.emplace(key, m_size);
            m_IndexKeyMap.emplace(m_size++, key);
        }
    }

    void delete_Key(T key)
    {
        if (m_KeyIndexMap.find(key) != m_KeyIndexMap.end())
        {
            int DeleteIndex = m_KeyIndexMap[key];
            int lastIndex = --m_size;
            T lastKey = m_IndexKeyMap[lastIndex];

            m_KeyIndexMap[lastKey] = DeleteIndex;
            m_KeyIndexMap.erase(key);
            m_IndexKeyMap[DeleteIndex] = lastKey;
            m_IndexKeyMap.erase(lastIndex);
        }
    }

    T getRandom()
    {
        if (m_size == 0)
            return T();
        std::uniform_int_distribution<int> u(0, m_size - 1);
        return m_IndexKeyMap[u(m_rng)];
    }
};

// 布隆过滤器(允许失误率)
// 黑名单或爬虫去重问题(只添加，不需要删除)(黑->白(不可能)，白->黑(可能))
// 以位图实现大大减少空间使用，与样本占用大小无关，只需要哈希函数可以接受样本大小的参数
// 由样本量与失误率，确定位图大小M，哈希函数个数k选择
// 失误率随M增大而减小(类似反比例形状),在固定M下失误率随k增大先下降再上升

// 并查集(两个功能的时间复杂度都很低O(1))
// 查询是否是一个集合
// 合并集合
template <typename T>
struct Element
{
    T val;
    Element(T val) : val(val) {}
};

template <typename T>
struct ElementHash
{
    std::size_t operator()(const Element<T> *element) const
    {
        return std::hash<T>()(element->val);
    }
};

template <typename T>
struct ElementEqual
{
    bool operator()(const Element<T> *lhs, const Element<T> *rhs) const
    {
        return lhs->val == rhs->val;
    }
};

template <typename T>
class UnionFinding
{
    std::unordered_map<T, Element<T> *> m_elementMap;
    std::unordered_map<Element<T> *, Element<T> *, ElementHash<T>, ElementEqual<T>> m_fatherMap;
    std::unordered_map<Element<T> *, int, ElementHash<T>, ElementEqual<T>> m_sizeMap;

    UnionFinding(const std::vector<T> &data)
    {
        for (const auto &val : data)
        {
            Element<T> *element = new Element<T>(val);
            m_elementMap.insert(std::make_pair(val, element));
            m_fatherMap.insert(std::make_pair(element, element));
            m_sizeMap.insert(std::make_pair<element, 1>);
        }
    }

    ~UnionFinding()
    {
        for (auto &cur : m_elementMap)
            delete cur->second;
    }

    bool isSameSet(const T &a, const T &b)
    {
        if (m_elementMap.find(a) != m_elementMap.end() && m_elementMap.find(b) != m_elementMap.end())
            return findHead(m_elementMap[a]) == findHead(m_elementMap[b]);
        return false;
    }

    void unionSet(const T &a, const T &b)
    {
        if (m_elementMap.find(a) != m_elementMap.end() && m_elementMap.find(b) != m_elementMap.end())
        {
            Element<T> *aF = findHead(m_elementMap[a]);
            Element<T> *bF = findHead(m_elementMap[b]);
            if (aF != bF)
            {
                Element<T> *big = m_sizeMap[aF] < m_sizeMap[bF] ? bF : aF;
                Element<T> *small = big == aF ? bF : aF;
                m_fatherMap[small] = big;
                m_sizeMap[big] += m_sizeMap[small];
                m_sizeMap.erase(small);
            }
        }
    }

    Element<T> *findHead(Element<T> *element)
    {
        std::stack<Element<T> *> path;
        while (element != m_fatherMap[element])
        {
            path.push(element);
            element = m_fatherMap[element];
        }
        while (!path.empty())
        {
            m_fatherMap[path.top()] = element;
            path.pop();
        }
        return element;
    }
};

// 岛屿问题
// 一个矩阵中只有0和1两种值，每个位置都可以和自己的上、下、左、右 四个位置相连，如
// 果有一片1连在一起，这个部分叫做一个岛，求一个矩阵中有多少个岛
int Islandcounts(std::vector<std::vector<int>> &grid);
void infect(std::vector<std::vector<int>> &grid, int i, int j, int rows, int columns);
