// Problem (short):
// Given a linked list, reorder it as first, last, second, second-last, and so on.

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
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        // Find middle of list using count (2-pass)
        int len = 0;
        ListNode *itr = head;
        while (itr)
        {
            len++;
            itr = itr->next;
        }

        int mid = len / 2;
        ListNode *slow = head;
        for (int i = 0; i < mid; i++)
            slow = slow->next;

        // Push second half into stack
        stack<ListNode *> st;
        ListNode *curr = slow->next;
        while (curr)
        {
            st.push(curr);
            curr = curr->next;
        }
        slow->next = nullptr;  // Cut the list in half

        // Alternate picking from first half and stack
        ListNode *first = head;
        while (first && !st.empty())
        {
            ListNode *fromStack = st.top();
            st.pop();

            ListNode *temp = first->next;
            first->next = fromStack;
            fromStack->next = temp;
            first = temp;
        }
    }
};
