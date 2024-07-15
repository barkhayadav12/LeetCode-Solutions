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
class BSTIterator{
    private:
    stack<TreeNode*>stk;
    bool fwd; //fwd->true means next, false means before
    public:
    BSTIterator(TreeNode*root,bool isForward)
    {
        fwd=isForward;
        pushAll(root);
    }
    int next()
    {
        TreeNode*temp=stk.top();
        stk.pop();
        if(fwd==true)
        {
            pushAll(temp->right);
        }
        else{
            pushAll(temp->left);
        }
        return temp->val;
    }
    void pushAll(TreeNode*root)
    {
        while(root!=NULL)
        {
            stk.push(root);
            if(fwd==true)
            {
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
    }
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
        {
            return false;
        }
        BSTIterator left(root,true);
        BSTIterator right(root,false);
        int i=left.next();
        int j=right.next();
        while(i<j)
        {
            if(i+j==k)
            {
                return true;
            }
            else if(i+j>k)
            {
                j=right.next();
            }
            else{
                i=left.next();
            }
        }
        return false;
    }
};