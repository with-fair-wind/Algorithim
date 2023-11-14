#include "Linked_List.h"

using namespace std;

void printSingleLinkedList(SingleNode *sNode)
{
    cout << "The Singlelinked list is: ";
    while (sNode != nullptr)
    {
        cout << sNode->value << " ";
        sNode = sNode->next;
    }
    cout << endl;
}

void printDoubleLinkedList(DoubleNode *dNode)
{
    cout << "The Doublelinked list is: ";
    DoubleNode *end = nullptr;
    while (dNode != nullptr)
    {
        cout << dNode->value << " ";
        end = dNode;
        dNode = dNode->next;
    }
    cout << "| ";
    while (end != nullptr)
    {
        cout << end->value << " ";
        end = end->last;
    }
    cout << endl;
}

void printRandLinkedList(RandomNode *rNode)
{
    cout << "The Randomlinked list is: " << endl;
    cout << "order: ";
    RandomNode *cur = rNode;
    while (cur != nullptr)
    {
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << endl;
    cout << "rand: ";
    cur = rNode;
    while (cur != nullptr)
    {
        cout << (cur->rand == nullptr ? "-" : to_string(cur->rand->value)) << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 调用后打印顺序相反
SingleNode *reverseLinkedList(SingleNode *head)
{
    if (head == nullptr)
        return nullptr;
    SingleNode *prev = nullptr;
    SingleNode *next = nullptr;
    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// 调用后打印Next顺序相反
DoubleNode *reverseDoubleList_v1(DoubleNode *head)
{
    if (head == nullptr)
        return nullptr;
    DoubleNode *prev = nullptr;
    DoubleNode *next = nullptr;
    while (head)
    {
        next = head->next;
        head->next = prev;
        head->last = next;
        prev = head;
        head = next;
    }
    return prev;
}

// 调用后打印Last顺序相同
void reverseDoubleList_v2(DoubleNode *head)
{
    if (head == nullptr)
        return;
    DoubleNode *prev = nullptr;
    DoubleNode *next = nullptr;
    while (head)
    {
        next = head->next;
        head->next = prev;
        head->last = next;
        prev = head;
        head = next;
    }
}

// 调用后打印Next顺序相反
void reverseDoubleList_v3(DoubleNode **head)
{
    if (head == nullptr || (*head) == nullptr)
        return;
    DoubleNode *prev = nullptr;
    DoubleNode *next = nullptr;
    while (*head)
    {
        next = (*head)->next;
        (*head)->next = prev;
        (*head)->last = next;
        prev = (*head);
        if (next == nullptr)
            return;
        else
            (*head) = next;
    }
}

void printCommonPart(SingleNode *head1, SingleNode *head2)
{
    cout << "Common Part: " << endl;
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->value < head2->value)
            head1 = head1->next;
        else if (head1->value > head2->value)
            head2 = head2->next;
        else
        {
            cout << head1->value << " " << endl;
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    cout << endl;
}

bool isPalindromeList_v1(SingleNode *head)
{
    if (head == nullptr)
        return false;
    SingleNode *cur = head;
    stack<SingleNode *> stackNode;
    while (cur != nullptr)
    {
        stackNode.push(cur);
        cur = cur->next;
    }
    while (!stackNode.empty())
    {
        if (stackNode.top()->value == head->value)
        {
            stackNode.pop();
            head = head->next;
        }
        else
            return false;
    }
    return true;
}

bool isPalindromeList_v2(SingleNode *head)
{
    if (head == nullptr)
        return false;
    if (head->next == nullptr)
        return true;
    // 从中点的后面第一个节点开始压栈
    SingleNode *slow = head->next, *quick = head;
    stack<SingleNode *> stackNode;
    while (quick->next != nullptr && quick->next->next != nullptr)
    {
        slow = slow->next;
        quick = quick->next->next;
    }
    while (slow != nullptr)
    {
        stackNode.push(slow);
        slow = slow->next;
    }
    while (!stackNode.empty())
    {
        if (stackNode.top()->value == head->value)
        {
            stackNode.pop();
            head = head->next;
        }
        else
            return false;
    }
    return true;
}

bool isPalindromeList_v3(SingleNode *head)
{
    if (head == nullptr)
        return false;
    SingleNode *slow = head, *quick = head;
    while (quick->next != nullptr && quick->next->next != nullptr)
    {
        slow = slow->next;
        quick = quick->next->next;
    }
    SingleNode *end = reverseLinkedList(slow), *tmp = end;
    while (head != nullptr && end != nullptr)
    {
        if (head->value == end->value)
        {
            head = head->next;
            end = end->next;
        }
        else
        {
            reverseLinkedList(tmp);
            return false;
        }
    }
    reverseLinkedList(tmp);
    return true;
}

SingleNode *listPartition_v1(SingleNode *head, int pivot)
{
    if (head == nullptr)
        return head;
    SingleNode *tmp = head;
    int count = 0;
    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }
    tmp = head;
    SingleNode **arr_Node = new SingleNode *[count];
    for (int i = 0; i < count; i++)
    {
        arr_Node[i] = tmp;
        tmp = tmp->next;
        // arr_Node[i]->next = nullptr;
    }
    pair<int, int> boundary(-1, count);
    int arr_index = 0;
    while (arr_index != boundary.second)
    {
        if (arr_Node[arr_index]->value < pivot)
            Swap_Node(arr_Node, ++boundary.first, arr_index++);
        else if (arr_Node[arr_index]->value == pivot)
            arr_index++;
        else
            Swap_Node(arr_Node, --boundary.second, arr_index);
    }
    for (int i = 0; i < count; i++)
    {
        if (i == count - 1)
            arr_Node[i]->next = nullptr;
        else
            arr_Node[i]->next = arr_Node[i + 1];
    }
    return arr_Node[0];
}

SingleNode *listPartition_v2(SingleNode *head, int pivot)
{
    SingleNode *small_H = nullptr, *small_L = nullptr;
    SingleNode *Equal_H = nullptr, *Equal_L = nullptr;
    SingleNode *Big_H = nullptr, *Big_L = nullptr;
    SingleNode *next = nullptr;
    while (head)
    {
        // 必须将每次加进来的头的next给置空，不然会弄出环形链表
        next = head->next;
        head->next = nullptr;
        if (head->value < pivot)
        {
            if (small_H == nullptr)
                small_H = head;
            else
                small_L->next = head;
            small_L = head;
            head = next;
        }
        else if (head->value == pivot)
        {
            if (Equal_H == nullptr)
                Equal_H = head;
            else
                Equal_L->next = head;
            Equal_L = head;
            head = next;
        }
        else
        {
            if (Big_H == nullptr)
                Big_H = head;
            else
                Big_L->next = head;
            Big_L = head;
            head = next;
        }
    }
    if (small_L)
    {
        small_L->next = Equal_H;
        Equal_L = Equal_L == nullptr ? small_L : Equal_L;
    }
    if (Equal_L)
        Equal_L->next = Big_H;
    return small_H != nullptr   ? small_H
           : Equal_H != nullptr ? Equal_H
                                : Big_H;
}

void Swap_Node(SingleNode **arr, int i, int j)
{
    SingleNode *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

RandomNode *copyListWithRand_v1(RandomNode *head)
{
    if (head == nullptr)
        return nullptr;
    unordered_map<RandomNode *, RandomNode *, RandomNodeHash, RandomNodeEqual> HashMap_Node;
    RandomNode *temp = head;
    while (temp)
    {
        HashMap_Node[temp] = new RandomNode(temp->value);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (temp->next)
            HashMap_Node[temp]->next = HashMap_Node[temp->next];
        if (temp->rand)
            HashMap_Node[temp]->rand = HashMap_Node[temp->rand];
        temp = temp->next;
    }
    return HashMap_Node[head];
}

RandomNode *copyListWithRand_v2(RandomNode *head)
{
    if (head == nullptr)
        return nullptr;
    RandomNode *cur = head;
    RandomNode *next = nullptr;
    while (cur)
    {
        next = cur->next;
        cur->next = new RandomNode(cur->value);
        cur->next->next = next;
        cur = next;
    }
    cur = head;
    RandomNode *curCopy = nullptr;
    while (cur)
    {
        cur->next->rand = cur->rand == nullptr ? nullptr : cur->rand->next; // 考虑nullptr
        cur = cur->next->next;
    }
    cur = head;
    RandomNode *res = head->next;
    while (cur)
    {
        next = cur->next->next;
        curCopy = cur->next;
        cur->next = next;
        curCopy->next = next == nullptr ? nullptr : next->next;
        cur = next;
    }
    return res;
}

SingleNode *getIntersectNode(SingleNode *head1, SingleNode *head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;
    SingleNode *loop1 = getLoopNode(head1);
    SingleNode *loop2 = getLoopNode(head2);
    if (loop1 == nullptr && loop2 == nullptr)
        return noLoop(head1, head2);
    else if (loop1 != nullptr && loop2 != nullptr)
        return bothLoop(head1, loop1, head2, loop2);
    else
        return nullptr;
}

SingleNode *getLoopNode(SingleNode *head)
{
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return nullptr;
    SingleNode *slow = head->next, *quick = head->next->next;
    while (slow != quick)
    {
        if (quick->next == nullptr || quick->next->next == nullptr)
            return nullptr;
        slow = slow->next;
        quick = quick->next->next;
    }
    quick = head;
    while (quick != slow)
    {
        quick = quick->next;
        slow = slow->next;
    }
    return slow;
}

SingleNode *noLoop(SingleNode *head1, SingleNode *head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;
    int num = 1;
    SingleNode *cur1 = head1, *cur2 = head2;
    while (cur1->next)
    {
        num++;
        cur1 = cur1->next;
    }
    while (cur2->next)
    {
        num--;
        cur2 = cur2->next;
    }
    if (cur1 != cur2)
        return nullptr;
    cur1 = num > 0 ? head1 : head2;
    cur2 = cur1 == head1 ? head2 : head1;
    num = abs(num);
    while (num != 0)
    {
        cur1 = cur1->next;
        num--;
    }
    while (cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

SingleNode *bothLoop(SingleNode *head1, SingleNode *loop1, SingleNode *head2, SingleNode *loop2)
{
    SingleNode *cur1 = head1, *cur2 = head2;
    if (loop1 == loop2)
    {
        int num = 0;
        while (cur1 != loop1)
        {
            num++;
            cur1 = cur1->next;
        }
        while (cur2 != loop2)
        {
            num--;
            cur2 = cur2->next;
        }
        cur1 = num > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        num = abs(num);
        while (num != 0)
        {
            cur1 = cur1->next;
            num--;
        }
        while (cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
    else
    {
        cur1 = loop1->next;
        while (cur1 != loop1)
        {
            if (cur1 == loop2)
                return loop1;
            cur1 = cur1->next;
        }
        return nullptr;
    }
}