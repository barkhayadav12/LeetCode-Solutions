class Solution {
public:
    int fn(int ind,vector<int>&nums,vector<int>&dp)
    {
        if(ind==0)
        {
            return nums[0];
        }
        if(ind<0)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int pick=nums[ind]+fn(ind-2,nums,dp);
        int not_pick=0+fn(ind-1,nums,dp);
        return dp[ind]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return fn(n-1,nums,dp);
    }
};