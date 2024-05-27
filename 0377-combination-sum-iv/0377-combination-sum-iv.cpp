class Solution {
public:
    int fn(vector<int>&nums,int target,vector<int>&dp)
    {
        if(target<0)
        {
            return 0;
        }
        if(target==0)
        {
            return 1;
        }
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        int currSum=0;
        for(int i=0;i<nums.size();i++)
        {
            int curr=nums[i];
            currSum+=fn(nums,target-curr,dp);
        }
        return dp[target]=currSum;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return fn(nums,target,dp);
    }
};