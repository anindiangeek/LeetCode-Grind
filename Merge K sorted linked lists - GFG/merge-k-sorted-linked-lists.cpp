// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    bool cmp(Node * p, Node * q)
    {
        return p->data>q->data;
    }
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        for(int i=K-1;i>=1;i--)
        {
            int p=i, q=i-1;
            Node * itr1=arr[p];
            Node * itr2=arr[q];
            Node * prev1 = nullptr;
            Node * temp= new Node(-1);
            Node * t=temp;
            while(itr1 && itr2)
            {
                if(itr1->data <= itr2->data)
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
            arr[q]=temp->next;
        }
        return arr[0];
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends