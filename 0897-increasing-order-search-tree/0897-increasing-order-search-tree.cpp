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
    void solve(TreeNode*root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        TreeNode*dummyNode=new TreeNode(-1);
        TreeNode*temp=dummyNode;
        for(int i=0;i<ans.size();i++)
        {
            TreeNode*newTreeNode=new TreeNode(ans[i]);
            temp->right=newTreeNode;
            temp->left=NULL;
            temp=newTreeNode;
        }
        return dummyNode->right;
    }
};