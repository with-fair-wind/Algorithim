// Key -> Value               Key 无value
// UnOrderedMap  UnSortedMap  UnOrderedSet  UnSortedSet  ->  哈希表
// 基础类型按值传递，非基础类型按引用传递(8位地址放于哈希表)

// Key->Value  Key 无value
// OrderedMap  OrderedSet  ->  有序表(根据Key有序组织)  非基础类型按引用传递必须提供比较器

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val = 0;
    ListNode *next = nullptr;
    ListNode(int x = 0, ListNode *n = nullptr) : val(x), next(n) {}
};

struct ListNodeHash
{
    std::size_t operator()(const ListNode *node) const
    {
        return std::hash<int>{}(node->val);
    }
};

struct ListNodeEqual
{
    bool operator()(const ListNode *lhs, const ListNode *rhs) const
    {
        return lhs->val == rhs->val;
    }
};

int main(int argc, char *argv[])
{
    unordered_map<ListNode *, ListNode *, ListNodeHash, ListNodeEqual> myMap;

    ListNode *n1 = new ListNode(1);
    n1->next = new ListNode(2);

    ListNode *n2 = new ListNode(5);
    n2->next = new ListNode(7);

    myMap[n1] = n2;

    cout << myMap[n1]->val << endl;

    n2->val = 9;

    cout << myMap[n1]->val << endl;

    return 0;
}
