class Solution {
public:
    int climb(int n,int dp[])
    {
        if(n<=1)
        {
            return dp[n]=1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n]=climb(n-1,dp)+climb(n-2,dp);
        return dp[n];
    }
   
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        return climb(n,dp);
    }
};