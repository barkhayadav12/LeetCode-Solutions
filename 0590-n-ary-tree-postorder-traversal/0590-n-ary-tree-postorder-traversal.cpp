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
    vector<int> postorder(Node* root) {
        vector<int>res;
        if(root==NULL)
        {
            return res;
        }
        stack<Node*>stk;
        stk.push(root);
        while(!stk.empty())
        {
            Node*curr=stk.top();
            stk.pop();
            for(auto it:curr->children)
            {
                stk.push(it);
            }
            res.push_back(curr->val);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};