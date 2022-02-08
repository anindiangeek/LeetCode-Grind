// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
     int length1 = 0, length2 = 0;

    bool HasIntersection = false;

    Node *itr1 = head1, *itr2 = head2, *IntersectionNode = nullptr;

    for (; itr1; itr1 = itr1->next, length1++)
        ;

    for (; itr2; itr2 = itr2->next, length2++)
        ;

    int skip = max(length1, length2) - min(length1, length2);

    itr1 = head1;
    itr2 = head2;

    if (length1 > length2)
        for (int i = 1; i <= skip; itr1 = itr1->next, i++)
            ;
    else if (length1 < length2)
        for (int i = 1; i <= skip; itr2 = itr2->next, i++)
            ;
    else
    {
        assert(skip == 0);
    }

    while (itr1 && itr2)
    {
        if (itr1->next == itr2->next && itr1->next != nullptr)
        {
            HasIntersection = true;
            IntersectionNode = itr1->next;
            return IntersectionNode->data;
        }
        itr1 = itr1->next;
        itr2 = itr2->next;
    }
    return -1;
}

