#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Student
{
    string name;
    int id;
    int age;                               // 结构体需要自己重载运算符<(大根堆)或者重载运算符>(小根堆)
    bool operator>(const Student &s) const // 所以后面的元素id需小于前面的id(代码中s.id即对应前面元素的id)
    {
        return id > s.id;
    }
};

struct SingleNode
{
    int value;
    SingleNode *next = nullptr;               // 结构体需要自己重载运算符<(大根堆)或者重载运算符>(小根堆)
    bool operator>(const SingleNode &s) const // 所以后面的元素id需大于前面的id(代码中s.id即对应前面元素的id)
    {
        return value > s.value;
    }
    SingleNode(int data) : value(data) {}
};

int main(void)
{
    priority_queue<Student, vector<Student>, greater<Student>> maxHeap; // 默认是less<student>(<)即后面的元素小于前面的元素形成大根堆
    Student student1 = {"kk", 3, 24};
    Student student2 = {"ty", 1, 25};
    Student student3 = {"qs", 2, 23};
    maxHeap.push(student1);
    maxHeap.push(student2);
    maxHeap.push(student3);

    while (!maxHeap.empty())
    {
        Student student = maxHeap.top();
        cout << "name: " << student.name << ", id: " << student.id << ", age: " << student.age << endl;
        maxHeap.pop();
    }

    cout << ((-1) >> 1) << endl;
    cout << ((-2) >> 1) << endl;

    cout << "===========================" << endl;

    priority_queue<SingleNode *, vector<SingleNode *>, greater<SingleNode *>> lessHeap;
    SingleNode *node1 = new SingleNode(2);
    SingleNode *node2 = new SingleNode(1);
    SingleNode *node3 = new SingleNode(4);
    lessHeap.push(node1);
    lessHeap.push(node2);
    lessHeap.push(node3);

    // lessHeap.pop();
    SingleNode *node4 = new SingleNode(5);
    lessHeap.push(node4);
    while (!lessHeap.empty())
    {
        SingleNode *node = lessHeap.top();
        cout << "value: " << node->value << endl;
        lessHeap.pop();
    }
    return 0;
}