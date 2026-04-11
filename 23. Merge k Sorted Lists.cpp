// Problem (short):
// Given k sorted linked lists, merge them into one sorted linked list.

#include <bits/stdc++.h>
using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };
// class Solution
// {
// public:
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         struct Cmp
//         {
//             bool operator()(ListNode *a, ListNode *b) const { return a->val > b->val; }
//         };
//         priority_queue<ListNode *, vector<ListNode *>, Cmp> pq;
//         for (auto p : lists)
//             if (p)
//                 pq.push(p);
//         ListNode dummy(0), *cur = &dummy;
//         while (!pq.empty())
//         {
//             ListNode *n = pq.top();
//             pq.pop();
//             cur->next = n;
//             cur = cur->next;
//             if (n->next)
//                 pq.push(n->next);
//         }
//         return dummy.next;
//     }
// };


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode dummy(0), *tail = &dummy;
        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int n = lists.size();
        ListNode* res=lists[0];
        
        if(n>1){
            for(int i=1; i <n; i++){
                res= mergeTwo(res, lists[i]);
            }
        }
        return res;
    }
};
