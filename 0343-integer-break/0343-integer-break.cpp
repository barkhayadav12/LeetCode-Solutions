class Solution {
public:
    int fn(int n,vector<int>&dp,int m)
    {
        if(n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            if(n-i>0)
            {
                ans=max(ans,i*fn(n-i,dp,m));
            }
        }
        if(n!=m){
            ans = max(ans,n);
        }
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return fn(n,dp,n);
    }
};