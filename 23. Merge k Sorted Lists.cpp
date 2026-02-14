#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val; ListNode* next; ListNode(int x):val(x),next(nullptr){} };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct Cmp{ bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; } };
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        for(auto p: lists) if(p) pq.push(p);
        ListNode dummy(0), *cur=&dummy;
        while(!pq.empty()){
            ListNode* n = pq.top(); pq.pop();
            cur->next = n; cur = cur->next;
            if(n->next) pq.push(n->next);
        }
        return dummy.next;
    }
};
