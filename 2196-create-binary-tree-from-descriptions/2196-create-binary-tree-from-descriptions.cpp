/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        //find root node
        unordered_map<int,TreeNode*>mpp;
        unordered_set<int>s;
        for(auto it:descriptions)
        {
            int parent=it[0];
            int child=it[1];
            int isLeft=it[2];
            if(mpp.find(parent)==mpp.end())
            {
                TreeNode*temp=new TreeNode(parent);
                mpp[parent]=temp;
            }
            if(mpp.find(child)==mpp.end())
            {
                TreeNode*temp=new TreeNode(child);
                mpp[child]=temp;
            }
            if(isLeft==1)
            {
                mpp[parent]->left=mpp[child];
            }
            else{
                mpp[parent]->right=mpp[child];
            }
            s.insert(child);
        }
        for(auto it:descriptions)
        {
            if(s.find(it[0])==s.end())
            {
                return mpp[it[0]];
            }
        }
        return NULL;
    }
};