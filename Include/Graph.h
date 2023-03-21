#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Fun.h"
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

// 生成最小生成树(k算法)
std::unordered_set<Edge *, EdgeHash, EdgeEqual> kruskalMST(Graph *Graph);
std::unordered_set<Edge *, EdgeHash, EdgeEqual> primMST(Graph *Graph);

std::unordered_map<Node *, int, NodeHash, NodeEqual> dijkstra1(Node *head);
Node *getMinDistanceAndUnselectedNode(std::unordered_map<Node *, int, NodeHash, NodeEqual>, std::unordered_set<Node *, NodeHash, NodeEqual>);
#endif