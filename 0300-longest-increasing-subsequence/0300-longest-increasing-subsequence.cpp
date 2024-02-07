class Solution {
public:
    int lis(vector<int>&nums,int n,int ind,int prev_ind,vector<vector<int>>&dp)
    {
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind][prev_ind+1]!=-1)
        {
            return dp[ind][prev_ind+1];
        }
        int notTake=0+lis(nums,n,ind+1,prev_ind,dp);
        int take=0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
        {
            take=1+lis(nums,n,ind+1,ind,dp);
        }
        return dp[ind][prev_ind+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return lis(nums,n,0,-1,dp);
    }
};