// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
     int GetLength(struct node *head)
    {
        int count{0};
        for (; head; count++, head = head->next)
            ;
        return count;
    }

    struct node *reverser(struct node *head, node *back, int k = -1)
    {
        /*
            for (int j = 0; j < k - 1; j++)
            {

                start->next = then->next;
                then->next = prev->next;
                prev->next = then;
                then = start->next;
            }

            prev = start;
         */
        node *pich = back;
        for (int j = 0; j < k; j++)
        {
            node *p = head->next;
            head->next = p->next;
            p->next = pich->next;
            pich->next = p;
            p = head->next;
        }
        return head;
    }
    struct node *reversee(struct node *head)
    {
        node *prev = nullptr;
        while (head)
        {
            node *p = head->next;
            head->next = prev;
            prev = head;
            head = p;
        }
        return prev;
    }
    struct node *reverse(struct node *head, int k)
    {
        if (k <= 1 || !head)
            return head;

        int length = GetLength(head);
        if (length == k)
            return reversee(head);
        if (length % k)
        {
            node *reversalpoint = head;
            for (int i = 1; i <= length -(length% k)-1; i++, reversalpoint = reversalpoint->next)
                ;
            reversalpoint->next = reversee(reversalpoint->next);
        }
        int skip = length / k;
        node *dummy = new node(-1);
        dummy->next = head;
        node *prev = dummy;

        for (int i = 0; i < skip; i++)
        {
            node *start = prev->next;
            node *then = start->next;
            prev = reverser(start, prev, k - 1);

            // for (int j = 0; j < k - 1; j++)
            // {

            //     start->next = then->next;
            //     then->next = prev->next;
            //     prev->next = then;
            //     then = start->next;
            // }

            // prev = start;
        }

        return dummy->next;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends