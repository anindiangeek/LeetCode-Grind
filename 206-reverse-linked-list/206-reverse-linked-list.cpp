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
    ListNode* reverse(ListNode* head)
    {
       if(head->next==nullptr){
           return head;
       }
           
       ListNode *temp=reverse(head->next);
       ListNode *q= head->next;
       q->next=head;
       head->next=nullptr;
        
       return temp;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head)
           return head;
        return reverse(head); 
    }
};