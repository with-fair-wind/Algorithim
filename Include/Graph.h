#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Fun.h"
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

struct Edge;
struct Node
{
    int val;
    int in;
    int out;
    std::vector<Node *> nexts;
    std::vector<Edge *> edges;
    Node(int data = 0)
    {
        val = data;
        in = 0;
        out = 0;
        nexts = std::vector<Node *>();
        edges = std::vector<Edge *>();
    }
};

struct NodeHash
{
    std::size_t operator()(const Node *node) const
    {
        std::size_t hash_val = std::hash<int>()(node->val);
        std::size_t hash_in = std::hash<int>()(node->in);
        std::size_t hash_out = std::hash<int>()(node->out);

        std::size_t combined_hash = hash_val ^ (hash_in << 1) ^ (hash_out << 2);
        // 考虑nexts
        for (const auto &next : node->nexts)
            combined_hash ^= (std::hash<const Node *>()(next) << 1);
        // 考虑edges
        for (const auto &edge : node->edges)
            combined_hash ^= (std::hash<const Edge *>()(edge) << 2);

        return combined_hash;
    }
};

struct NodeEqual
{
    bool operator()(const Node *lhs, const Node *rhs) const
    {
        bool val_equal = lhs->val == rhs->val;
        bool in_equal = lhs->in == rhs->in;
        bool out_equal = lhs->out == rhs->out;

        bool nexts_equal = lhs->nexts.size() == rhs->nexts.size();
        if (nexts_equal)
        {
            for (size_t i = 0; i < lhs->nexts.size(); ++i)
            {
                if (lhs->nexts[i] != rhs->nexts[i])
                {
                    nexts_equal = false;
                    break;
                }
            }
        }

        bool edges_equal = lhs->edges.size() == rhs->edges.size();
        if (edges_equal)
        {
            for (size_t i = 0; i < lhs->edges.size(); ++i)
            {
                if (lhs->edges[i] != rhs->edges[i])
                {
                    edges_equal = false;
                    break;
                }
            }
        }

        return val_equal && in_equal && out_equal && nexts_equal && edges_equal;
    }
};

struct Edge
{
    int weight;
    Node *from;
    Node *to;
    Edge(int data = 0, Node *from = nullptr, Node *to = nullptr) : weight(data), from(from), to(to) {}
};

struct Cmp_edge
{
    bool operator()(const Edge *n1, const Edge *n2) const
    {
        return n1->weight > n2->weight; // 小根堆
    }
};

struct EdgeHash
{
    std::size_t operator()(const Edge *edge) const
    {
        std::size_t hash_weight = std::hash<int>()(edge->weight);
        std::size_t hash_from = std::hash<Node *>()(edge->from);
        std::size_t hash_to = std::hash<Node *>()(edge->to);

        std::size_t combined_hash = hash_weight ^ (hash_from << 1) ^ (hash_to << 2);

        return combined_hash;
    }
};

struct EdgeEqual
{
    bool operator()(const Edge *lhs, const Edge *rhs) const
    {
        bool weight_equal = lhs->weight == rhs->weight;
        bool from_equal = lhs->from == rhs->from;
        bool to_equal = lhs->to == rhs->to;

        return weight_equal && from_equal && to_equal;
    }
};

struct UnionFind
{
    std::unordered_map<Node *, std::list<Node *> *, NodeHash, NodeEqual> UnionSet;

    void makeSet(const std::list<Node *> &nodeList)
    {
        for (auto cur : nodeList)
            UnionSet.insert(std::make_pair(cur, new std::list<Node *>{cur}));
    }

    bool isSameSet(Node *n1, Node *n2) const
    {
        if (n1 == nullptr || n2 == nullptr || UnionSet.find(n1) == UnionSet.end() || UnionSet.find(n2) == UnionSet.end())
            return false;
        return UnionSet.at(n1) == UnionSet.at(n2);
    }

    void Union(Node *n1, Node *n2)
    {
        if (n1 == nullptr || n2 == nullptr || UnionSet.find(n1) == UnionSet.end() || UnionSet.find(n2) == UnionSet.end())
            return;
        if (!isSameSet(n1, n2))
        {
            for (auto cur : *(UnionSet.at(n2)))
                UnionSet.at(n1)->push_back(cur);
            UnionSet.at(n2) = UnionSet.at(n1);
        }
    }
};

struct Graph
{
    std::unordered_map<int, Node *> nodes;
    std::unordered_set<Edge *, EdgeHash, EdgeEqual> edges;
    Graph()
    {
        nodes = std::unordered_map<int, Node *>();
        edges = std::unordered_set<Edge *, EdgeHash, EdgeEqual>();
    }
};

// 图的层序遍历(只需要给一个节点就可以)
void BFS(Node *node);
// 图的深度遍历(只需要给一个节点就可以)
void DFS_v1(Node *node);
void DFS_v2(Node *node);
// 图的拓扑排序
std::list<Node *> *sortedTopology(Graph *graph);

// 生成最小生成树(k、p算法)
std::unordered_set<Edge *, EdgeHash, EdgeEqual> kruskalMST(Graph *Graph);
std::unordered_set<Edge *, EdgeHash, EdgeEqual> primMST(Graph *Graph);

// 最短路径问题
// 从head出发，所有head能达到的节点，生成到达每个节点的最小路径记录并返回
std::unordered_map<Node *, int, NodeHash, NodeEqual> dijkstra1(Node *head);
Node *getMinDistanceAndUnselectedNode(std::unordered_map<Node *, int, NodeHash, NodeEqual> &distanceMap, std::unordered_set<Node *, NodeHash, NodeEqual> &selectedNodes);
// 改写堆的实现
class NodeHeap
{
private:
    std::vector<Node *> nodeVec;
    std::unordered_map<Node *, int, NodeHash, NodeEqual> heapIndexMap; // 小根堆中的node对应与vector的索引，用于判断是否在堆中，是否进入过堆
    std::unordered_map<Node *, int, NodeHash, NodeEqual> distanceMap;
    int heapSize;

public:
    NodeHeap()
    {
        nodeVec = std::vector<Node *>();
        heapIndexMap = std::unordered_map<Node *, int, NodeHash, NodeEqual>();
        distanceMap = std::unordered_map<Node *, int, NodeHash, NodeEqual>();
        heapSize = 0;
    }

    bool isEmpty() { return heapSize == 0; }
    bool isEntered(Node *node) { return heapIndexMap.find(node) != heapIndexMap.end(); }
    bool isInheap(Node *node)
    {
        if (isEntered(node))
            return heapIndexMap[node] != -1;
        return false;
    }

    void heapify(int index, int heapSize)
    {
        int left = index * 2 + 1;
        while (left < heapSize)
        {
            int least = left + 1 < heapSize && distanceMap[nodeVec[left + 1]] < distanceMap[nodeVec[left]] ? left + 1 : left;
            least = distanceMap[nodeVec[least]] < distanceMap[nodeVec[index]] ? least : index;
            if (least == index)
                return;
            swap_node(index, least);
            index = least;
            left = index * 2 + 1;
        }
    }

    void heapinsert(int index)
    {
        while (distanceMap[nodeVec[index]] < distanceMap[nodeVec[((index - 1) >> 1)]])
        {
            swap_node(index, ((index - 1) >> 1));
            index = ((index - 1) >> 1);
        }
    }

    void swap_node(int i, int j)
    {
        heapIndexMap[nodeVec[i]] = j;
        heapIndexMap[nodeVec[j]] = i;
        Node *tmp = nodeVec[i];
        nodeVec[i] = nodeVec[j];
        nodeVec[j] = tmp;
    }

    std::pair<Node *, int> pop()
    {
        std::pair<Node *, int> res(nodeVec[0], distanceMap[nodeVec[0]]);
        swap_node(0, --heapSize);
        heapify(0, heapSize);
        heapIndexMap[nodeVec[heapSize]] = -1;
        distanceMap.erase(nodeVec[heapSize]);
        nodeVec.erase(nodeVec.end() - 1);
        return res;
    }

    void addOrUpdateOrIgnore(Node *node, int new_distance)
    {
        if (isInheap(node))
        {
            distanceMap[node] = std::min(distanceMap[node], new_distance);
            heapinsert(heapIndexMap[node]);
        }
        if (!isEntered(node))
        {
            nodeVec[heapSize] = node;
            heapIndexMap[node] = heapSize;
            distanceMap[node] = new_distance;
            heapinsert(heapSize++);
        }
    }
};

std::unordered_map<Node *, int, NodeHash, NodeEqual> dijkstra2(Node *head);
#endif