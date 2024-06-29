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
    int fn(TreeNode*root,int prev)
    {
        if(root==NULL)
        {
            return 0;
        }
        int res=0;
        if(root->val>=prev)
        {
            res+=1;
            prev=root->val;
        }
        return res+ fn(root->left,prev)+fn(root->right,prev);
    }
    int goodNodes(TreeNode* root) {
        int prev=root->val;
        return fn(root,prev);
    }
};