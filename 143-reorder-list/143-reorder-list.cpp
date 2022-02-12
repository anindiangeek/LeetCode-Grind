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
    private:
        ListNode * itr;
        bool okay;
public:
    void reorder(ListNode * head)
    {
        if(head==nullptr)
            return;
        reorder(head->next);
        
        if(!okay)
        {
            ListNode* NextMarker= itr->next;
            itr->next=head;
            head->next=NextMarker;
            itr=NextMarker;
        }
        
        if(itr && itr->next==head)
        {
            itr->next=nullptr;
            okay=true;
        }
            
    }
    void reorderList(ListNode* head) {
        itr=head;
        okay=false;
        reorder(head);
    }
};