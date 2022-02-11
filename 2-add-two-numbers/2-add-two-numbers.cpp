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
    ListNode * Reverse(ListNode * head)
    {
        ListNode * prev=nullptr;
        while(head)
        {
            ListNode * n=head->next;
            head->next=prev;
            prev=head;
            head=n;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=Reverse(l1);
        // l2=Reverse(l2);
        ListNode * answer=new ListNode(-1);
        ListNode * a=answer,* itr1=l1, * itr2=l2;
        
        int carry=0, sum=0;
      
      while(itr1 && itr2)
      {
         sum = carry;
         sum +=itr1->val;
         sum +=itr2->val;
         carry = sum/10;
         a->next=new ListNode(sum%10);
         a=a->next;
        itr1=itr1->next;
        itr2=itr2->next;
      }
      while(itr1)
      {
          a->next =new ListNode((itr1->val + carry)%10);
          a=a->next;
          carry=(itr1->val + carry) /10;
          itr1=itr1->next;
      }
      while(itr2)
      {
          a->next =new ListNode((itr2->val + carry) % 10);
          a=a->next;
          carry=(itr2->val + carry) /10;
          itr2=itr2->next;
      }
      if(carry)
      {
          a->next=new ListNode(carry);
          a=a->next;
      }
      // answer->next=Reverse(answer->next);
      return answer->next;
        
    }
};