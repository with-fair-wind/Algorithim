#include <iostream>
#include <queue>

struct Node
{
    int val;
    Node(int val = 0) : val(val) {}
};

struct cmp
{
    bool operator()(const Node *n1, const Node *n2) const
    {
        return n1->val > n2->val; // 小根堆
    }
};

int main()
{
    std::priority_queue<Node *, std::vector<Node *>, cmp> q;
    q.push(new Node(3));
    q.push(new Node(1));
    q.push(new Node(4));
    q.push(new Node(1));
    while (!q.empty())
    {
        std::cout << q.top()->val << " ";
        q.pop();
    }
    std::cout << std::endl;
    return 0;
}
