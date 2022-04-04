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
public:
    ListNode* swapNodes(ListNode* head, int k, int length=0) {
        ListNode *begin=head,*end=head,*itr=head;
        for(;itr;length++,itr=itr->next);
        for(int i=k-1;i;i--,begin=begin->next);
        for(int i=length-k;i;i--,end=end->next);
        swap(begin->val,end->val);
        return head;  
    }
};