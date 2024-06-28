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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool isEven=true;
        while(!q.empty())
        {
            int n=q.size();
            int prev=isEven? INT_MIN : INT_MAX;
            for(int i=0;i<n;i++)
            {
                auto it=q.front();
                if(isEven && (it->val<=prev || it->val%2==0))
                {
                    return false;
                }
                if(!isEven && (it->val>=prev || it->val%2!=0))
                {
                    return false;
                }
                q.pop();
                if(it->left)
                {
                    q.push(it->left);
                }
                if(it->right)
                {
                    q.push(it->right);
                }
                prev=it->val;
            }
            isEven=!isEven;
        }
        return true;
    }
};