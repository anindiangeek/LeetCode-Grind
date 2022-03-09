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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy= new ListNode(0);
        ListNode *d=dummy;
        d->next=head;
        
        while(head)
        {
            if(head->next && head->val==head->next->val)
            {
                while(head->next && head->val == head->next->val)
                    head=head->next;
                d->next=head->next;
            }
            else
                d=d->next;
            
            head=head->next;
            
        }
        return dummy->next; 
    }
};