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
    // void in_order(TreeNode*root,vector<int>&op)
    // {
    //     if(root==NULL)
    //     {
    //         return;
    //     }
    //     in_order(root->left,op);
    //     op.push_back(root->val);
    //     in_order(root->right,op);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int>op;
        // in_order(root,op);
        // return op;
        TreeNode*curr=root;
        vector<int>ans;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                //print and go right
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode*leftChild=curr->left;
                //extreme right pe jao
                while(leftChild->right!=NULL)
                {
                    leftChild=leftChild->right;
                }
                //right ko curr se connect krdo
                leftChild->right=curr;
                //detach krdo link between curr and curr->left, but uske pehle go to current's left
                TreeNode*temp=curr;
                //go to curr's left
                curr=curr->left;
                //detach
                temp->left=NULL;
            }
        }
        return ans;
    }
};