#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val) : value(val){}
};

int main(void)
{   
    

    return 0;
}

TreeNode *buildTree1(int * pre, int pre_len, int * in, int in_len)
{
    if (pre == nullptr || in == nullptr || pre_len != in_len)
        return nullptr;
    unordered_map<int,int> hashMap;
    for (int i = 0; i < in_len; i++)
        hashMap.insert(pair<int, int>(in[i], i));
    return f1(pre, 0, pre_len - 1, in, 0, in_len - 1, hashMap);
}

//  有一棵树，先序结果是pre[L1...R1],中序结果是in[L2...R2]
TreeNode * f1(int * pre, int L1, int R1, int * in, int L2, int R2, unordered_map<int,int> m)
{
    if (L1 > R1)
        return nullptr;
    TreeNode *head = new TreeNode(pre[L1]);
    if (L1 == R1)
        return head;
    int find = m.find(pre[L1])->second;
    head->left = f1(pre, L1 + 1, L1 + find - L2, in, L2, find - 1, m);
    head->right = f1(pre, L1 + find - L2 + 1, R1, in, find + 1, R2, m);
}

TreeNode *buildTree2(int * pre, int pre_len, int * in, int in_len)
{
    if (pre == nullptr || in == nullptr || pre_len != in_len)
        return nullptr;
    
    return f2(pre, 0, pre_len - 1, in, 0, in_len - 1);
}

//  有一棵树，先序结果是pre[L1...R1],中序结果是in[L2...R2]
TreeNode * f2(int * pre, int L1, int R1, int * in, int L2, int R2)
{
    if (L1 > R1)
        return nullptr;
    TreeNode *head = new TreeNode(pre[L1]);
    if (L1 == R1)
        return head;
    int find = L2;
    for (;find != pre[L1]; find++);
    head->left = f2(pre, L1 + 1, L1 + find - L2, in, L2, find - 1);
    head->right = f2(pre, L1 + find - L2 + 1, R1, in, find + 1, R2);
}
