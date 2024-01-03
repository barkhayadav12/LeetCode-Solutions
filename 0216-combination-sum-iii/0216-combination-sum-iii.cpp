class Solution {
public:
    void printCombination(vector<int>&nums,int i,int sum,vector<int>&v,vector<vector<int>>&ans,int k,int n)
    {
        if(i==nums.size())
        {
            if(sum==n && v.size()==k)
            {
                ans.push_back(v);
            }
            return;
        }
        v.push_back(nums[i]);
        sum+=nums[i];
        printCombination(nums,i+1,sum,v,ans,k,n);
        v.pop_back();
        sum-=nums[i];
        printCombination(nums,i+1,sum,v,ans,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<int>v;
        vector<vector<int>>ans;
        printCombination(nums,0,0,v,ans,k,n);
        return ans;
        
        
    }
};