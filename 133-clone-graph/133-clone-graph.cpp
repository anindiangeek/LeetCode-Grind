/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> Hash;
    void dfs(Node * node)
    {
         Node *temp = node;
         for (auto x : temp->neighbors)
            {
                if (Hash.find(x) == Hash.end())
                {
                    Node *NewNode = new Node(x->val);
                    Hash[x] = NewNode;
                    dfs(x);
                }
                Hash[temp]->neighbors.push_back(Hash[x]);
            }
    }

    Node* cloneGraph(Node* node) 
    {
        if(!node)  return {};
        Node *NG = new Node(node->val);
        Hash[node] = NG;
        dfs(node);
        return NG;
    }
};