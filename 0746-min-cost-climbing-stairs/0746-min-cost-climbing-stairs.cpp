class Solution {
public:
    int fn(int n,vector<int>&cost,vector<int>&dp)
    {
        if(n==0 || n==1)
        {
            return cost[n];
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=min(cost[n]+fn(n-1,cost,dp),cost[n]+fn(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(fn(n-1,cost,dp),fn(n-2,cost,dp));
        
    }
};