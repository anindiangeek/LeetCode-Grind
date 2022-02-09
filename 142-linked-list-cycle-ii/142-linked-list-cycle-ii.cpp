/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //flyod's cycle detection (gift wala) method.
        if(!head)
            return nullptr;
        bool HasCycle=false;
        ListNode *slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                HasCycle=true;
                 break;
            }
        }
        fast=head;
        while(slow && fast)
        {
             if(slow==fast)
                break;
            fast=fast->next;

            slow=slow->next;
           
        }
           return HasCycle?fast:nullptr;
    }
};