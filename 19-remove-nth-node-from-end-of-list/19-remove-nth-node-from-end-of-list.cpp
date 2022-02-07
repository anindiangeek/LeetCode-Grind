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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // nth element from end will be length-i+1 th element form the begining.
                if(!head)
            return head;
        
        ListNode* ForwardNode=head,*BackNode=head;
        
        while(n--)
            ForwardNode=ForwardNode->next;
        
        if(!ForwardNode)
                return head->next;
        while(ForwardNode->next)
        {
            BackNode=BackNode->next;
            ForwardNode=ForwardNode->next;
        }
        //deleting the node.
       
       BackNode->next=BackNode->next->next;

        return head;
    }
};