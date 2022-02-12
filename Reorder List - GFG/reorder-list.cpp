// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node * reverse(Node *head)
{
    Node * prev=nullptr;
    while(head)
    {
        Node * next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;
}

void reorderList(Node* head) {
    
    if(!head or !head->next)
        return;
        
    // getting the middle element
    Node * slow=head, * fast=head;
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    // slow is the middle element 
    
    //splititng the list and reversing the half list
    slow->next=reverse(slow->next);
    Node * b = slow->next;
    Node *itr=head;
    Node * temp = itr->next;
    slow->next=nullptr;
    while(b && temp)
    {
        temp=itr->next;
        Node * temp2 = b->next;
        itr->next=b;
        b->next=temp;
        b=temp2;
        itr=temp;
    }
}