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
    int GetLength(ListNode *head)
    {
        int count{0};
        for(;head;count++,head=head->next)
            ;
        return count;
    }
    ListNode *reverse(ListNode* start,ListNode * back,int k)
    {
        ListNode *prev=back;
        for(int i=0;i<k;i++)
        {
            ListNode * temp=start->next;
            start->next=temp->next;
            temp->next=prev->next;
            prev->next=temp;
        }
        return start;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or k<=1)
                return head;
        
        int length=GetLength(head);
        
        int blocks=length/k;
        
        ListNode *dummy =new ListNode(-1);
        dummy->next=head;
        
        ListNode *previous=dummy;
        for(int i=0;i<blocks;i++)
        {
            ListNode* start=previous->next;
            previous=reverse(start,previous,k-1);
        }
        return dummy->next;
    }
};