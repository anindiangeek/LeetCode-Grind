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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return nullptr;
        
        ListNode * Odd  = new ListNode(INT_MIN); 
        ListNode * Even = new ListNode(INT_MIN);  
        ListNode * o    = Odd;   //odd node iterator
        ListNode * e    = Even; // even node iterator 
        ListNode * itr  = head; // iterator         
        for(int Index = 1 ; itr ; Index++, itr=itr->next)
        {
            if(Index & 1) // if it is a Odd numbered index
            {
                o->next=itr;
                o=o->next;
            }
            else
            {
                e->next=itr;
                e=e->next;
            }
        }
        if(o)
            o->next=Even->next;
        if(e)
            e->next=nullptr;
        return Odd->next;
    }
};