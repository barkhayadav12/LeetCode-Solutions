class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        int i1=1;
        int i2=1;
        int i3=1;
        for(int i=2;i<=n;i++)
        {
            int temp1=dp[i1]*2;
            int temp2=dp[i2]*3;
            int temp3=dp[i3]*5;
            int mini=min(temp1,min(temp2,temp3));
            dp[i]=mini;
            if(mini==temp1)
            {
                i1++;
            }
            if(mini==temp2)
            {
                i2++;
            }
            if(mini==temp3)
            {
                i3++;
            }
        }
        return dp[n];
    }
};