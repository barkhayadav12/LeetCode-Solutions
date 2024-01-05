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
    void in_order(TreeNode*root,vector<int>&op)
    {
        if(root==NULL)
        {
            return;
        }
        in_order(root->left,op);
        op.push_back(root->val);
        in_order(root->right,op);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>op;
        in_order(root,op);
        return op;
    }
};