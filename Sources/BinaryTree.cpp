#include "BinaryTree.h"

using namespace std;

void preOrderRecur(TreeNode *head)
{
    if (head == nullptr)
        return;
    cout << head->val << " ";
    preOrderRecur(head->left);
    preOrderRecur(head->right);
    // cout << endl;
}

void inOrderRecur(TreeNode *head)
{
    if (head == nullptr)
        return;
    preOrderRecur(head->left);
    cout << head->val << " ";
    preOrderRecur(head->right);
    // cout << endl;
}
void posOrderRecur(TreeNode *head)
{
    if (head == nullptr)
        return;
    preOrderRecur(head->left);
    preOrderRecur(head->right);
    cout << head->val << " ";
    // cout << endl;
}

void preOrderUnRecur(TreeNode *head)
{
    cout << "pre-order: ";
    if (head == nullptr)
        return;
    stack<TreeNode *> stackNode;
    stackNode.push(head);
    while (!stackNode.empty())
    {
        TreeNode *node = stackNode.top();
        stackNode.pop();
        cout << node->val << " ";
        if (node->right)
            stackNode.push(node->right);
        if (node->left)
            stackNode.push(node->left);
    }
    //(头左右)
    cout << endl;
}

void inOrderUnRecur(TreeNode *head)
{
    cout << "in-order: ";
    if (head == nullptr)
        return;
    stack<TreeNode *> stackNode;
    while (head)
    {
        stackNode.push(head);
        head = head->left;
    }
    while (!stackNode.empty())
    {
        TreeNode *node = stackNode.top();
        stackNode.pop();
        cout << node->val << " "; // 已经是(左头)的打印顺序了，再看每个作为头的节点的右数也遵循这样的规则(将右数分解为(左头左头...))
        node = node->right;
        if (node)
        {
            while (node)
            {
                stackNode.push(node);
                node = node->left;
            }
        }
    }
}

void posOrderUnRecur(TreeNode *head)
{
    cout << "pos-order: ";
    if (head == nullptr)
        return;
    stack<TreeNode *> stackNode;
    stack<TreeNode *> stackPos;
    stackNode.push(head);
    while (!stackNode.empty())
    {
        TreeNode *node = stackNode.top();
        stackNode.pop();
        stackPos.push(node);
        if (node->left)
            stackNode.push(node->left);
        if (node->right)
            stackNode.push(node->right);
    }
    //(头右左)
    while (!stackPos.empty())
    {
        TreeNode *cur = stackPos.top();
        stackPos.pop();
        cout << cur->val << " ";
    }
    cout << endl;
}

int getMaxWidth(TreeNode *head)
{
    if (head == NULL)
        return 0;
    queue<TreeNode *> myQueue;
    myQueue.push(head);
    TreeNode *curend = head, *nextend = nullptr, *cur = nullptr;
    int maxWidth = 1, curWidth = 0;
    while (!myQueue.empty())
    {
        cur = myQueue.front();
        myQueue.pop();
        curWidth++;
        if (cur->left)
        {
            myQueue.push(cur->left);
            nextend = cur->left;
        }
        if (cur->right)
        {
            myQueue.push(cur->right);
            nextend = cur->right;
        }
        if (cur == curend)
        {
            maxWidth = max(maxWidth, curWidth);
            curWidth = 0;
            curend = nextend;
            nextend = nullptr;
        }
    }
    return maxWidth;
}

bool isBST_v1(TreeNode *head)
{
    if (head == nullptr)
        return true;
    list<int> myList;
    process_v1(head, myList);
    int prev = INT_MIN;
    for (int num : myList)
    {
        if (num <= prev)
            return false;
        prev = num;
    }
    return true;
}

void process_v1(TreeNode *head, list<int> &myList)
{
    if (head == nullptr)
        return;
    process_v1(head, myList);
    myList.push_back(head->val);
    process_v1(head, myList);
}

bool isBST_v2(TreeNode *head)
{
    if (head == nullptr)
        return true;
    return process_v2(head)->first;
}

pair<bool, pair<int, int>> *process_v2(TreeNode *head)
{
    if (head == nullptr)
        return nullptr;
    pair<bool, pair<int, int>> *left = process_v2(head->left);
    pair<bool, pair<int, int>> *right = process_v2(head->right);
    int minNum = head->val, maxNum = head->val;
    if (left)
    {
        minNum = min(minNum, left->second.first);
        maxNum = max(maxNum, left->second.second);
    }
    if (right)
    {
        minNum = min(minNum, right->second.first);
        maxNum = max(maxNum, right->second.second);
    }
    bool isBST = true;
    if ((left != nullptr && (!left->first || left->second.second >= head->val)) ||
        (right != nullptr && (!right->first || right->second.first <= head->val)))
        isBST = false;
    return new pair<bool, pair<int, int>>(isBST, pair<int, int>(minNum, maxNum));
}

bool isCBT(TreeNode *head)
{
    if (head == nullptr)
        return true;
    queue<TreeNode *> myQueue;
    myQueue.push(head);
    // TreeNode *left = nullptr, *right = nullptr;
    bool remain = false;
    while (!myQueue.empty())
    {
        TreeNode *cur = myQueue.front();
        myQueue.pop();
        // 有右无左 或者 已经必须是叶节点的时候(remain == true)如果还孩子
        if ((remain && (cur->left != nullptr || cur->right != nullptr)) ||
            (cur->right != nullptr && cur->left == nullptr))
            return false;
        // 如果孩子不双全时(有左无右，后者没有孩子时)后续节点必须全是叶节点
        if (cur->left == nullptr || cur->right == nullptr)
            remain = true;
        if (cur->left)
            myQueue.push(cur->left);
        if (cur->right)
            myQueue.push(cur->right);
    }
    return true;
}

bool isBalanced(TreeNode *head)
{
    return process_v3(head).first;
}

pair<bool, int> process_v3(TreeNode *head)
{
    if (head == nullptr)
        return make_pair(true, 0);
    pair<bool, int> p1 = process_v3(head->left);
    pair<bool, int> p2 = process_v3(head->right);
    int height = max(p1.second, p2.second) + 1;
    bool isBalanced = p1.first && p2.first && (abs(p1.second - p2.second) < 2) ? true : false;
    return make_pair(isBalanced, height);
}

bool isFull(TreeNode *head)
{
    if (head == nullptr || (head->left == nullptr && head->right == nullptr))
        return true;
    if (head->left != nullptr && head->right != nullptr)
        return isFull(head->left) && isFull(head->right);
    else
        return false;
}

TreeNode *lowestCommonAncestor(TreeNode *head, TreeNode *o1, TreeNode *o2)
{
    if (o1 == nullptr && o2 == nullptr)
        return nullptr;
    if (head == nullptr || head == o1 || head == o2)
        return head;
    TreeNode *left = lowestCommonAncestor(head->left, o1, o2);
    TreeNode *right = lowestCommonAncestor(head->right, o1, o2);
    if (left != nullptr && right != nullptr)
        return head;
    else
        return left != nullptr ? left : right;
}

PTreeNode *getSuccessorNode(PTreeNode *node)
{
    if (node == nullptr)
        return nullptr;
    if (node->right)
    {
        node = node->right;
        while (node->left)
            node = node->left;
        return node;
    }
    else
    {
        PTreeNode *father = node->father;
        while (father != nullptr && father->left != node)
        {
            node = father;
            father = node->father;
        }
        return father;
    }
}

string serialByPre(TreeNode *head)
{
    if (head == nullptr)
        return "#_";
    string res = to_string(head->val) + "_";
    res += serialByPre(head->left);
    res += serialByPre(head->right);
    return res;
}

TreeNode *reconByPreString(string preStr)
{
    stringstream ss(preStr);
    queue<string> strQueue;
    string temp;
    while (getline(ss, temp, '_'))
    {
        if (!temp.empty())
            strQueue.push(temp);
    }
    return reconPreOrder(strQueue);
}

// 必须是引用或者指针，否则在head->left递归调用后strQueue发生改变，但其实改变的只是拷贝而已，返回到递归调用head->right的栈空间时,strQueue依然是递归调用head->left前的strQueue，从而发生错误
TreeNode *reconPreOrder(queue<string> &strQueue)
{
    if (strQueue.empty())
        return nullptr;
    string strFront = strQueue.front();
    strQueue.pop();
    if (strFront == "#")
        return nullptr;
    TreeNode *head = new TreeNode(stoi(strFront));
    head->left = reconPreOrder(strQueue);
    head->right = reconPreOrder(strQueue);
    return head;
}

void PrintPaperFolding(int N)
{
    // 此处将第一层也就是第一个节点为当前节点，将其作为根节点以中序遍历打印
    process_v4(1, N, true);
}

void process_v4(int i, int N, bool down)
{
    if (i > N)
        return;
    process_v4(i + 1, N, true);
    cout << (down ? "凹" : "凸") << " ";
    process_v4(i + 1, N, false);
}

int maxDistance(TreeNode *head)
{
    return process_v5(head).first;
}

pair<int, int> process_v5(TreeNode *head)
{
    if (head == nullptr)
        return make_pair(0, 0);
    pair<int, int> leftInfo = process_v5(head->left);
    pair<int, int> rightInfo = process_v5(head->right);
    int maxDistance = std::max(leftInfo.second + rightInfo.second + 1, (std::max(leftInfo.first, rightInfo.first)));
    int maxHeight = std::max(leftInfo.second, rightInfo.second) + 1;
    return make_pair(maxDistance, maxHeight);
}

int maxHappy(Employee *head)
{
    pair<int, int> maxHappy = process_v6(head);
    return std::max(maxHappy.first, maxHappy.second);
}

pair<int, int> process_v6(Employee *head)
{
    if (head->subordinates.empty())
        return make_pair(head->happy, 0);
    int noHeadMaxVal = 0, headMaxVal = head->happy;
    for (const auto &cur : head->subordinates)
    {
        pair<int, int> res = process_v6(cur);
        noHeadMaxVal += std::max(res.first, res.second);
        headMaxVal += res.second;
    }
    return make_pair(headMaxVal, noHeadMaxVal);
}

void morris(TreeNode *head)
{
    if (head == nullptr)
        return;
    TreeNode *cur = head;
    TreeNode *mostRight = nullptr;
    while (cur)
    {
        mostRight = cur->left;
        if (mostRight)
        {
            while (mostRight->right != nullptr && mostRight->right != cur)
                mostRight = mostRight->right;
            if (mostRight->right == nullptr) // 第一次遍历到此节点cur
            {
                mostRight->right = cur;
                cur = cur->left;
                continue;
            }
            mostRight->right = nullptr; // 第二次遍历到此节点cur
        }
        cur = cur->right; // 没有左孩子只会被遍历一次
    }
}

void morrisIn(TreeNode *head)
{
    if (head == nullptr)
        return;
    TreeNode *cur = head;
    TreeNode *mostRight = nullptr;
    while (cur)
    {
        mostRight = cur->left;
        if (mostRight)
        {
            while (mostRight->right != nullptr && mostRight->right != cur)
                mostRight = mostRight->right;
            if (mostRight->right == nullptr)
            {
                mostRight->right = cur;
                cur = cur->left;
                continue;
            }
            mostRight->right = nullptr;
        }
        cout << cur->val << " ";
        cur = cur->right;
    }
    cout << endl;
}

void morrisPre(TreeNode *head)
{
    if (head == nullptr)
        return;
    TreeNode *cur = head;
    TreeNode *mostRight = nullptr;
    while (cur)
    {
        mostRight = cur->left;
        if (mostRight)
        {
            while (mostRight->right != nullptr && mostRight->right != cur)
                mostRight = mostRight->right;
            if (mostRight->right == nullptr)
            {
                cout << cur->val << " ";
                mostRight->right = cur;
                cur = cur->left;
                continue;
            }
            mostRight->right = nullptr;
        }
        else
            cout << cur->val << " ";
        cur = cur->right;
    }
    cout << endl;
}

// 逆序打印左树右边界
void morrisPos(TreeNode *head)
{
    if (head == nullptr)
        return;
    TreeNode *cur = head;
    TreeNode *mostRight = nullptr;
    while (cur)
    {
        mostRight = cur->left;
        if (mostRight)
        {
            while (mostRight->right != nullptr && mostRight->right != cur)
                mostRight = mostRight->right;
            if (mostRight->right == nullptr) // 第一次遍历到此节点cur
            {
                mostRight->right = cur;
                cur = cur->left;
                continue;
            }
            mostRight->right = nullptr; // 第二次遍历到此节点cur
            printInReverse(cur->left);  // ***一定要放在上一句代码下面***
        }
        cur = cur->right;
    }
    printInReverse(head);
    cout << endl;
}

void printInReverse(TreeNode *head)
{
    TreeNode *tail = reserveRightTree(head);
    TreeNode *cur = tail;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->right;
    }
    reserveRightTree(tail);
}

TreeNode *reserveRightTree(TreeNode *head)
{
    if (head == nullptr)
        return nullptr;
    TreeNode *prev = nullptr;
    TreeNode *next = nullptr;
    while (head)
    {
        next = head->right;
        head->right = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isBST_v3(TreeNode *head)
{
    if (head == nullptr)
        return true;
    TreeNode *cur = head;
    TreeNode *mostRight = nullptr;
    int prevNum = INT_MIN;
    while (cur)
    {
        mostRight = cur->left;
        if (mostRight)
        {
            while (mostRight->right != nullptr && mostRight->right != cur)
                mostRight = mostRight->right;
            if (mostRight->right == nullptr)
            {
                mostRight->right = cur;
                cur = cur->left;
                continue;
            }
            mostRight->right = nullptr;
        }
        if (cur->val < prevNum)
            return false;
        prevNum = cur->val;
        cur = cur->right;
    }
    return true;
}
