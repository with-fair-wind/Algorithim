#include "Graph.h"

using namespace std;

void BFS(Node *node)
{
    if (node == nullptr)
        return;
    queue<Node *> mapQueue;
    unordered_set<Node *, NodeHash, NodeEqual> mapSet; // 对于简单数据，可以用数组或vector代替
    mapQueue.push(node);
    mapSet.insert(node);
    while (!mapQueue.empty())
    {
        Node *cur = mapQueue.front();
        mapQueue.pop();
        cout << cur->val << " ";
        while (!cur->nexts.empty())
        {
            for (Node *tmp : cur->nexts)
            {
                if (mapSet.find(tmp) == mapSet.end())
                {
                    mapQueue.push(tmp);
                    mapSet.insert(tmp);
                }
            }
        }
    }
}

void DFS_v1(Node *node)
{
    if (node == nullptr)
        return;
    static unordered_set<Node *, NodeHash, NodeEqual> mapSet;
    mapSet.insert(node);
    cout << node->val << " ";
    for (Node *tmp : node->nexts)
    {
        if (mapSet.find(tmp) == mapSet.end())
            DFS_v1(tmp);
    }
}

void DFS_v2(Node *node)
{
    if (node == nullptr)
        return;
    stack<Node *> mapStack;
    unordered_set<Node *, NodeHash, NodeEqual> mapSet;
    mapStack.push(node);
    mapSet.insert(node);
    cout << node->val << " ";
    while (!mapStack.empty())
    {
        Node *cur = mapStack.top();
        mapStack.pop();
        for (Node *tmp : cur->nexts)
        {
            if (mapSet.find(tmp) == mapSet.end())
            {
                mapStack.push(cur);
                mapStack.push(tmp);
                mapSet.insert(tmp);
                cout << tmp->val << " ";
                break;
            }
        }
    }
}

list<Node *> *sortedTopology(Graph *graph)
{
    // 节点对应的入度
    unordered_map<Node *, int, NodeHash, NodeEqual> NodeInMap;
    // 只有入度为零才能进队列
    queue<Node *> ZeroInQueue;
    auto iter = graph->nodes.begin();
    for (; iter != graph->nodes.end(); iter++)
    {
        NodeInMap.insert(make_pair(iter->second, iter->second->in));
        if (iter->second->in == 0)
            ZeroInQueue.push(iter->second);
    }
    list<Node *> *res = new list<Node *>;
    while (!ZeroInQueue.empty())
    {
        Node *cur = ZeroInQueue.front();
        ZeroInQueue.pop();
        res->push_back(cur);
        for (Node *tmp : cur->nexts)
        {
            if (--NodeInMap.find(tmp)->second == 0)
                ZeroInQueue.push(tmp);
        }
    }
    return res;
}

unordered_set<Edge *, EdgeHash, EdgeEqual> kruskalMST(Graph *Graph)
{
    UnionFind *unionFind = new UnionFind();
    list<Node *> allNodes;
    for (auto cur : Graph->nodes)
        allNodes.push_back(cur.second);
    unionFind->makeSet(allNodes);
    priority_queue<Edge *, vector<Edge *>, Cmp_edge> priorityEdges;
    for (Edge *edge : Graph->edges)
        priorityEdges.push(edge);
    unordered_set<Edge *, EdgeHash, EdgeEqual> res;

    while (!priorityEdges.empty())
    {
        Edge *cur = priorityEdges.top();
        priorityEdges.pop();
        if (!unionFind->isSameSet(cur->from, cur->to))
        {
            unionFind->Union(cur->from, cur->to);
            res.insert(cur);
        }
    }
    return res;
}

unordered_set<Edge *, EdgeHash, EdgeEqual> primMST(Graph *Graph)
{
    priority_queue<Edge *, vector<Edge *>, Cmp_edge> priorityEdges;
    unordered_set<Node *, NodeHash, NodeEqual> nodeSet;
    unordered_set<Edge *, EdgeHash, EdgeEqual> res;

    // 最外层for是森林问题(一个图分几个整体连通)
    for (auto tmp : Graph->nodes)
    {
        if (nodeSet.find(tmp.second) == nodeSet.end())
        {
            nodeSet.insert(tmp.second);
            for (auto edge : tmp.second->edges)
                priorityEdges.push(edge);
        }
        while (!priorityEdges.empty())
        {
            Edge *cur = priorityEdges.top();
            priorityEdges.pop();
            if (nodeSet.find(cur->to) != nodeSet.end())
            {
                nodeSet.insert(cur->to);
                res.insert(cur);
                for (auto edge : cur->to->edges)
                    priorityEdges.push(edge);
            }
        }
    }
    return res;
}

unordered_map<Node *, int, NodeHash, NodeEqual> dijkstra1(Node *head)
{
}

Node *getMinDistanceAndUnselectedNode(unordered_map<Node *, int, NodeHash, NodeEqual>, unordered_set<Node *, NodeHash, NodeEqual>)
{
}