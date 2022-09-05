/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(Node *root)
    {
        if (!root)
            return {};
        queue<Node *> q;
        q.push(root);
        ans.push_back({root->val});

        while (!q.empty())
        {
            int size = q.size();
            vector<int> t;
            while (size--)
            {
                   Node *temp = q.front();
                    q.pop();
                for (auto nodes : temp->children)
                {
                    q.push(nodes);
                    t.push_back(nodes->val);
                }
            }
            if (t.size())
                ans.push_back(t);
        }
        return ans;
    }
};