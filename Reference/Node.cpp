/// 系统中有个独立的区域叫NULL，约定好的地址叫空

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct SingleNode
{
    int value;
    SingleNode *next = nullptr; // 结构体需要自己重载运算符<(大根堆)或者重载运算符>(小根堆)
    SingleNode(int data) : value(data) {}
    bool operator<(const SingleNode *s) const // 所以后面的元素id需大于前面的id(代码中s.id即对应前面元素的id)
    {
        return value > s->value;
    }
};

bool cmp(SingleNode *s1, SingleNode *s2)
{
    return s1->value > s2->value;
}

struct DoubleNode
{
    int value;
    DoubleNode *next = nullptr;
    DoubleNode *last = nullptr;
    DoubleNode(int data) : value(data) {}
};

template <class T>
struct TypeNode
{
    T value;
    TypeNode *next = nullptr;
    TypeNode(T data) : value(data) {}
};

template <class T>
class MyQueue
{
private:
    TypeNode<T> *head;
    TypeNode<T> *tail;
    int size;
    T pollValue;

public:
    MyQueue();
    ~MyQueue();
    bool isEmpty() { return size == 0; }
    int Size() { return size; }
    T show() { return pollValue; }
    void offer(T val);
    void poll();
    void peek();
};

template <class T>
MyQueue<T>::MyQueue() : head(nullptr), tail(nullptr), size(0) {}

template <class T>
MyQueue<T>::~MyQueue()
{
    TypeNode<T> *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void MyQueue<T>::offer(T val)
{
    TypeNode<T> *cur = new TypeNode<T>(val);
    if (tail == nullptr)
    {
        head = cur;
        tail = cur;
    }
    else
    {
        tail->next = cur;
        tail = cur;
    }
    size++;
}

template <class T>
void MyQueue<T>::poll()
{
    if (head != nullptr)
    {
        TypeNode<T> *temp = head;
        pollValue = head->value;
        head = head->next;
        size--;
        delete temp;
        temp = nullptr;
        cout << "tail's value: " << tail->value << endl;
    }
    if (head == nullptr)
    {
        tail = nullptr;
        cout << "List is empty!" << endl;
    }
}

template <class T>
void MyQueue<T>::peek()
{
    if (head != nullptr)
        pollValue = head->value;
}

SingleNode *reverseLinkedList(SingleNode *head);

DoubleNode *reverseDoubleList1(DoubleNode *head);
void reverseDoubleList2(DoubleNode *head);
void reverseDoubleList3(DoubleNode **head);

SingleNode *getGroupEnd(SingleNode *start, int k);
void reverse(SingleNode *start, SingleNode *end);
SingleNode *reverseKGroup(SingleNode *head, int k);

int ListLength(SingleNode *head);
SingleNode *AddTwoNums(SingleNode *head1, SingleNode *head2);

SingleNode *mergeTwoLists(SingleNode *head1, SingleNode *head2);

SingleNode *mergeKList(SingleNode *arr[], int K);

int main(int argc, char *argv[])
{
    /// 单链表反转
    SingleNode *n1 = new SingleNode(1);
    n1->next = new SingleNode(2);
    n1->next->next = new SingleNode(3);
    n1 = reverseLinkedList(n1); // 此时n1是按值传递，不是按引用传递，
    while (n1 != nullptr)
    {
        cout << n1->value << " ";
        n1 = n1->next;
    }
    cout << endl;

    /// 双链表反转
    DoubleNode *n2 = new DoubleNode(1);
    n2->next = new DoubleNode(2);
    n2->next->next = new DoubleNode(3);
    n2->next->last = n2;
    n2->next->next->last = n2->next->next;
    n2 = reverseDoubleList1(n2);
    while (n2 != nullptr)
    {
        cout << n2->value << " ";
        n2 = n2->next;
    }
    cout << endl;

    DoubleNode *n3 = new DoubleNode(1);
    n3->next = new DoubleNode(2);
    n3->next->next = new DoubleNode(3);
    n3->next->last = n3;
    n3->next->next->last = n3->next->next;
    reverseDoubleList2(n3);
    while (n3 != nullptr)
    {
        cout << n3->value << " ";
        n3 = n3->last;
    }
    cout << endl;

    DoubleNode *n4 = new DoubleNode(1);
    n4->next = new DoubleNode(2);
    n4->next->next = new DoubleNode(3);
    n4->next->last = n4;
    n4->next->next->last = n4->next->next;
    reverseDoubleList3(&n4);
    while (n4 != nullptr)
    {
        cout << n4->value << " ";
        n4 = n4->next;
    }
    cout << endl;

    /// 队列
    MyQueue<int> queue;
    if (queue.isEmpty())
        cout << "MyQueue is empty" << endl;
    queue.offer(3);
    queue.offer(5);
    cout << "Size: " << queue.Size() << endl;
    cout << "-------------" << endl;
    queue.poll();
    cout << "Now size is " << queue.Size() << endl;
    cout << "PollValue is " << queue.show() << endl;
    cout << "-------------" << endl;
    queue.poll();
    cout << "Now size is " << queue.Size() << endl;
    cout << "PollValue is " << queue.show() << endl;
    cout << "-------------" << endl;
    queue.poll();

    SingleNode *n5 = new SingleNode(1);
    n5->next = new SingleNode(2);
    n5->next->next = new SingleNode(3);

    SingleNode *n6 = new SingleNode(2);
    n6->next = new SingleNode(3);
    n6->next->next = new SingleNode(4);

    SingleNode *n7 = new SingleNode(1);
    n7->next = new SingleNode(2);
    n7->next->next = new SingleNode(5);

    SingleNode *arr[] = {n5, n6, n7};

    SingleNode *lessHead = mergeKList(arr, 3);

    while (lessHead != nullptr)
    {
        cout << lessHead->value << " ";
        lessHead = lessHead->next;
    }
    cout << endl;

    SingleNode *addNode1 = new SingleNode(9);
    SingleNode *cur1 = addNode1;
    for (int i = 0; i < 6; i++)
    {
        addNode1->next = new SingleNode(9);
        addNode1 = addNode1->next;
    }
    SingleNode *addNode2 = new SingleNode(9);
    SingleNode *cur2 = addNode2;
    for (int i = 0; i < 3; i++)
    {
        addNode2->next = new SingleNode(9);
        addNode2 = addNode2->next;
    }
    SingleNode *ans = AddTwoNums(cur1, cur2);
    while (ans != nullptr)
    {
        cout << ans->value << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}

SingleNode *reverseLinkedList(SingleNode *head)
{
    SingleNode *pre = nullptr;
    SingleNode *next = nullptr;
    while (head != nullptr)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

DoubleNode *reverseDoubleList1(DoubleNode *head)
{
    DoubleNode *next = nullptr;
    DoubleNode *pre = nullptr;
    while (head != nullptr)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head->last = next;
        head = next;
    }
    return pre;
}

void reverseDoubleList2(DoubleNode *head)
{
    DoubleNode *next = nullptr;
    DoubleNode *pre = nullptr;
    while (head != nullptr)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head->last = next;
        head = next;
    }
}

void reverseDoubleList3(DoubleNode **head)
{
    DoubleNode *next = nullptr;
    DoubleNode *pre = nullptr;
    while ((*head) != nullptr)
    {
        next = (*head)->next;
        (*head)->next = pre;
        pre = (*head);
        (*head)->last = next;
        if (next != nullptr)
            (*head) = next;
        else
            return;
    }
}

// 单链表实现栈
// 双链表实现双端队列(从头部加，从头部弹，从尾部加，从尾部弹O(1 ))

// K个节点的组内逆序调整
// 实现从start开始数到的第k个节点并返回
SingleNode *getGroupEnd(SingleNode *start, int k)
{
    while (--k != 0 && start != nullptr)
        start = start->next;
    return start;
}

// 实现从start开始，到end节点的逆序，并实现start的下个节点是end的下个节点
void reverse(SingleNode *start, SingleNode *end)
{
    end = end->next;
    SingleNode *pre = nullptr;
    SingleNode *cur = start;
    SingleNode *next = nullptr;
    while (cur != end)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    start->next = end;
}

SingleNode *reverseKGroup(SingleNode *head, int k)
{
    SingleNode *start = head;
    SingleNode *end = getGroupEnd(start, k);
    if (end == nullptr)
        return head;
    else
    {
        head = end;
        reverse(start, end);
        SingleNode *lastStart = start;
        while (lastStart->next != nullptr)
        {
            start = lastStart->next;
            end = getGroupEnd(start, k);
            if (end == nullptr)
                return head;
            else
            {
                reverse(start, end);
                lastStart->next = end;
                lastStart = start;
            }
        }
    }
    return head;
}

// 两个链表相加
int ListLength(SingleNode *head)
{
    int len = 0;
    while (head != nullptr)
    {
        len++;
        head = head->next;
    }
    return len;
}

SingleNode *AddTwoNums(SingleNode *head1, SingleNode *head2)
{
    int len1 = ListLength(head1);
    int len2 = ListLength(head2);
    SingleNode *lHead = len1 > len2 ? head1 : head2; // 记录长链表的头节点作为返回
    SingleNode *curs = lHead == head1 ? head2 : head1;
    SingleNode *curl = lHead; // 随动节点
    SingleNode *last = curl;
    int carry = 0;
    int curNum = 0;
    while (curs != nullptr)
    {
        curNum = curl->value + curs->value + carry;
        curl->value = curNum % 10;
        carry = curNum / 10;
        last = curl;
        curl = curl->next;
        curs = curs->next;
    }
    while (curl != nullptr)
    {
        curNum = curl->value + carry;
        curl->value = curNum % 10;
        carry = curNum / 10;
        last = curl;
        curl = curl->next;
    }
    while (carry != 0)
    {
        last->next = new SingleNode(1);
        carry = 0;
    }
    return lHead;
}

// 两个有序链表合并
SingleNode *mergeTwoLists(SingleNode *head1, SingleNode *head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return head1 == nullptr ? head2 : head1;
    SingleNode *head = head1->value < head2->value ? head1 : head2;
    SingleNode *pre = head;
    SingleNode *cur1 = head->next;
    SingleNode *cur2 = head == head1 ? head2 : head1;
    while (cur1 != nullptr && cur2 != nullptr)
    {
        if (cur1->value < cur2->value)
        {
            pre->next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            pre->next = cur2;
            cur2 = cur2->next;
        }
        pre = pre->next;
    }
    pre->next = cur1 == nullptr ? cur2 : cur1;
    return head;
}

// 合并K个升序列表
SingleNode *mergeKList(SingleNode *arr[], int K)
{
    if (arr == nullptr)
        return nullptr;
    priority_queue<SingleNode *, vector<SingleNode *>, decltype(&cmp)> lessHeap(cmp);
    for (int i = 0; i < K; i++)
    {
        lessHeap.push(arr[i]);
    }
    if (lessHeap.empty())
        return nullptr;
    SingleNode *head = lessHeap.top();
    SingleNode *pre = head;
    lessHeap.pop();
    while (!lessHeap.empty())
    {
        SingleNode *cur = pre->next;
        if (cur != nullptr)
            lessHeap.push(cur);
        pre->next = lessHeap.top();
        pre = pre->next;
        lessHeap.pop();
    }

    return head;
}
