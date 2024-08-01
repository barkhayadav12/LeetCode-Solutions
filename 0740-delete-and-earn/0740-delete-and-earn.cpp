class Solution {
public:
    // sort krdo
    // value same hai toh lelo, agar value nums[curr]+1 hai toh skip krdo
    int solve(int ind,vector<int>&nums,vector<int>&dp)
    {
        //base case
        int n=nums.size();
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        // not pick
        int not_take=0+solve(ind+1,nums,dp);
        int take=0;
        int i=ind,sum=0;
        while(i<n && nums[i]==nums[ind])
        {
            sum+=nums[ind];
            i++;
        }
        while(i<n && nums[i]==nums[ind]+1)
        {
            i++;
        }
        take=sum+solve(i,nums,dp);
        return dp[ind]=max(take,not_take);
        
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
        
    }
};