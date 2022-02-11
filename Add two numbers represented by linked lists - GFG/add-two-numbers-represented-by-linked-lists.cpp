// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node * reverse(struct Node * head)
    {
        Node * prev=nullptr;
        while(head)
        {
            Node* q=head->next;
            head->next=prev;
            prev=head;
            head=q;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
      first=reverse(first);
      second=reverse(second);

      Node *itr1=first,*itr2=second;
      
      Node *answer=new Node(0);
      
      Node *a=answer;
      
      int carry=0, sum=0;
      
      while(itr1 && itr2)
      {
         sum = carry;
         sum +=itr1->data;
         sum +=itr2->data;
         carry = sum/10;
         a->next=new Node(sum%10);
         a=a->next;
        itr1=itr1->next;
        itr2=itr2->next;
      }
      while(itr1)
      {
          a->next =new Node((itr1->data + carry)%10);
          a=a->next;
          carry=(itr1->data + carry) /10;
          itr1=itr1->next;
      }
      while(itr2)
      {
          a->next =new Node((itr2->data + carry) % 10);
          a=a->next;
          carry=(itr2->data + carry) /10;
          itr2=itr2->next;
      }
      if(carry)
      {
          a->next=new Node(carry);
          a=a->next;
      }
      answer->next=reverse(answer->next);
      return answer->next;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends