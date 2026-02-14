#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val; ListNode* next; ListNode(int x):val(x),next(nullptr){} };
class Solution {
    ListNode* reverseList(ListNode* head){ ListNode* prev=nullptr; while(head){ auto nxt=head->next; head->next=prev; prev=head; head=nxt;} return prev; }
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next) return;
        ListNode* slow=head; ListNode* fast=head;
        while(fast&&fast->next){ slow=slow->next; fast=fast->next->next; }
        ListNode* second=reverseList(slow->next); slow->next=nullptr;
        ListNode* first=head;
        while(second){ ListNode* t1=first->next, *t2=second->next; first->next=second; second->next=t1; first=t1; second=t2; }
    }
};
