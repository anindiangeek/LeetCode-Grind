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
            // there exists a naive method in which we iterate through list and calculate the length
        // then return the answer after reiterating through half of the elements.
        
        /*
            Using fast and slow pointers
            one pointer will move twice as fast than the other while one reaches the end the other will 
            be in the middle of it.
        */
    ListNode* middleNode(ListNode* head) {
        if(!head)
           return nullptr;
        ListNode *fast=head,*slow=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};