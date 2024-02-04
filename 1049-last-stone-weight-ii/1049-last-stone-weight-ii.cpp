class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int range=0;
        for(int i=0;i<stones.size();i++)
        {
            range+=stones[i];
        }
        int n=stones.size();
        bool dp[n+1][range+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<range+1;j++)
            {
                if(i==0)
                {
                    dp[i][j]=false;
                }
                if(j==0)
                {
                    dp[i][j]=true;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<range+1;j++)
            {
                if(stones[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-stones[i-1]]||dp[i-1][j];
                }
                else if(stones[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int ans=INT_MAX;
        for(int j=range/2;j>=0;j--)
        {
            if(dp[n][j]==true)
            {
                ans=range-2*j;
                break;
            }
        }
        return ans;  
    }
};