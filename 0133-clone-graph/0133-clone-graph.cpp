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
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        unordered_map<Node*,Node*>mpp;
        queue<Node*>q;
        Node*copy=new Node(node->val,{});
        mpp[node]=copy;
        q.push(node);
        while(!q.empty())
        {
            Node*curr=q.front();
            q.pop();
            for(auto it:curr->neighbors)
            {
                if(mpp.find(it)==mpp.end())
                {
                    Node*neighbor=new Node(it->val,{});
                    mpp[it]=neighbor;
                    q.push(it);
                }
                mpp[curr]->neighbors.push_back(mpp[it]);
            }
        }
        return copy;
    }
};