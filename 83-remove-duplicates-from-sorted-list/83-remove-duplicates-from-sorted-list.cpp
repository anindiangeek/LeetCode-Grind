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
        if(!head or !head->next) return head;
        ListNode * dummy = new ListNode(0);
        ListNode * d=dummy,*prev=nullptr,*itr=head;
        while(itr)
        {
            ListNode *temp = itr;
            while(temp->next && temp->val==temp->next->val)
                temp=temp->next;
            itr->next=temp->next;
            itr=itr->next;
        }
        return head;

    }
};