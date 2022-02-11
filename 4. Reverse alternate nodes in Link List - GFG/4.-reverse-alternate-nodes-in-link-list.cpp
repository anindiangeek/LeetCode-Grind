// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


 // } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node * Reverse(Node *head)
    {
		Node * prev=nullptr;
		while(head)
		{
				Node * n= head->next;
				head->next=prev;
				prev=head;
				head=n;
		}
		return prev;
    }

    void rearrange(struct Node *head)
    {
       if(!head or !head->next)
        return;

	    Node * left= new Node(-1);
	    Node * right= new Node(-1);
	    Node * l=left,*r=right,*itr=head;

    for(int index=1 ; itr ;index++,itr=itr->next) // O(N) 
	    {
			if(index & 1)
			{
					l->next=itr;
					l=l->next;
			}
			else
			{
					r->next=itr;
					r=r->next;
			}
	     }
	     r->next=nullptr;
		    Node * headofright=Reverse(right->next);
			l->next=headofright;
			head=left->next;
        }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}
  // } Driver Code Ends