// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start

// Definition for singly-linked list.

class Solution
{
public:
    int ListLength(ListNode *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int len1 = ListLength(l1);
        int len2 = ListLength(l2);
        ListNode *lHead = len1 > len2 ? l1 : l2; // 记录长链表的头节点作为返回
        ListNode *curs = lHead == l1 ? l2 : l1;
        ListNode *curl = lHead; // 随动节点
        ListNode *last = curl;
        int carry = 0;
        int curNum = 0;
        while (curs != nullptr)
        {
            curNum = curl->val + curs->val + carry;
            curl->val = curNum % 10;
            carry = curNum / 10;
            last = curl;
            curl = curl->next;
            curs = curs->next;
        }
        while (curl != nullptr)
        {
            curNum = curl->val + carry;
            curl->val = curNum % 10;
            carry = curNum / 10;
            last = curl;
            curl = curl->next;
        }
        while (carry != 0)
        {
            last->next = new ListNode(1);
            carry = 0;
        }
        return lHead;
    }
};
// @lc code=end
