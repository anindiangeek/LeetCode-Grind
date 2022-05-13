class Solution {
public:
    Node* connect(Node* root) {
        Node *dummy = new Node(0, NULL, NULL, NULL), *cur = dummy, *head = root;
        while (root) {
            for (auto i: {root->left, root->right}) // handel left, rigt child in order by moving cur cursor.
                if(i) cur = cur->next = i;            
            
            root = root->next;
            if (!root) {//NULL value means scannning of current level is done. 
                        //Reset cur as dummy，root as dummy->next，which is first node of next level
                cur = dummy;
                root = dummy->next;
                //if(dummy->next) cout<< dummy->next->val << endl; // this will print first node of each coming level
                dummy->next = NULL; // delink dummy since its duty of marking position is accomplished. Plus, it is also a must to avoid dead-loop
            }
        }
        return head;
    }
};
