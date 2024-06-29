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
    void fn(TreeNode*root1,vector<int>&num)
    {
        if(root1->left==NULL && root1->right==NULL)
        {
            num.push_back(root1->val);
            return;
        }
        if(root1->left)
        {
            fn(root1->left,num);
        }
        if(root1->right)
        {
            fn(root1->right,num);
        }
    }
    void fn_2(TreeNode*root2,vector<int>&num_2)
    {
        if(root2->left==NULL && root2->right==NULL)
        {
            num_2.push_back(root2->val);
            return;
        }
        if(root2->left)
        {
            fn_2(root2->left,num_2);
        }
        if(root2->right)
        {
            fn_2(root2->right,num_2);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>num;
        vector<int>num_2;
        fn(root1,num);
        fn_2(root2,num_2);
        if(num.size()!=num_2.size())
        {
            return false;
        }
        for(int i=0;i<num.size();i++)
        {
            if(num[i]!=num_2[i])
            {
                return false;
            }
        }
        return true;
    }
};