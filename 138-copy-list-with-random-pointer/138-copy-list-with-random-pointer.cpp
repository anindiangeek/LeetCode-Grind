/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        
        
        Node *itr = head;
        Node *temp = nullptr;
        while (itr)
        {
            temp = itr->next;
            Node *RedNode = new Node(itr->val);
            itr->next = RedNode;
            RedNode->next = temp;
            itr = temp;
        }
        // generated a black and red node sequence.

        itr = head;
        while (itr)
        {
            itr->next->random = (!itr->random) ? itr->random : itr->random->next;
            itr=itr->next->next;
        }

        // getting my list back the list of all red nodes.
        Node * BlackNodes=head, * RedNodes=head->next;
        Node * answer=RedNodes;
        while(RedNodes)
        {
            BlackNodes->next=BlackNodes->next->next;
            RedNodes->next=(!RedNodes->next)? nullptr : RedNodes->next->next;
            BlackNodes= BlackNodes->next;
            RedNodes=RedNodes->next;
        }
        return answer;
    }
};