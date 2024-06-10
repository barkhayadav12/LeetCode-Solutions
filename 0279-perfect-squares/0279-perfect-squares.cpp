class Solution {
public:
    bool checkperfectsquare(int n)
    {
    if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
        return true;
    }
    else {
        return false;
    }
    }
    int fn(int n,vector<int>&dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=1e9;
        for(int i=1;i*i<=n;i++)
        {
            if((n-i)>=0)
            {
                ans=min(ans,1+fn(n-i*i,dp));
            }
        }
        return dp[n]=ans;
    }
    
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return fn(n,dp);
    }
};