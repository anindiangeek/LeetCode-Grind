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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(!lists.size()) return nullptr;
         for(int i=lists.size()-1;i>=1;i--)
         {
            int p=i, q=i-1;
            ListNode * itr1=lists[p];
            ListNode * itr2=lists[q];
            ListNode * temp= new ListNode(-1);
            ListNode * t=temp;
            while(itr1 && itr2)
            {
                if(itr1->val <= itr2->val)
                {
                    t->next=itr1;
                    itr1=itr1->next;
                }
                else
                {
                    t->next=itr2;
                    itr2=itr2->next;
                }
                t=t->next;
            }
            while(itr1)
            {
                t->next=itr1;
                t=t->next;
                itr1=itr1->next;
            }
            while(itr2)
            {
                t->next=itr2;
                t=t->next;
                itr2=itr2->next;
            }
            lists[q]=temp->next;
        }
        return lists[0];
    }
};