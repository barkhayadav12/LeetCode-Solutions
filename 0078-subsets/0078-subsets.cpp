class Solution {
public:
    void printSubset(vector<int>&nums,int i,vector<vector<int>>&ans,vector<int>&res)
    {
        if(i>=nums.size())
        {
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        printSubset(nums,i+1,ans,res);
        res.pop_back();
        printSubset(nums,i+1,ans,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        vector<vector<int>>ans;
        printSubset(nums,0,ans,res);
        return ans;
    }
};