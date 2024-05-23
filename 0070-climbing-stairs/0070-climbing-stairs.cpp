class Solution {
public:
    int climb(int n,int dp[])
    {
       if(n==0)
       {
           return 1;
       }
       if(n<0)
       {
           return 0;
       }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<=2;i++)
        {
            ans=ans+climb(n-i,dp);
        }
        return dp[n]=ans;
    }
   
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        return climb(n,dp);
    }
};