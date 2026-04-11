// Problem (short):
// Given a linked list, remove the nth node from the end and return the head.

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return head;

        int count = 0;
        ListNode *itr = head;
        while (itr)
        {
            count++;
            itr = itr->next;
        }

        if (n == count)
            return head->next;

        itr = head;
        for (int i = 1; i < count - n; i++)
            itr = itr->next;

        if (itr->next)
            itr->next = itr->next->next;

        return head;
    }
};
