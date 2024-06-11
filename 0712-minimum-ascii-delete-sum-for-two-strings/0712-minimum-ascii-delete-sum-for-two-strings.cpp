class Solution {
public:
    int lcs(string a,string b,int i,int j,vector<vector<int>>&dp)
    {
        int n=a.length();
        int m=b.length();
        if(i==n || j==m)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j])
        {
            ans=a[i]+lcs(a,b,i+1,j+1,dp);
        }
        else{
            ans=max(lcs(a,b,i+1,j,dp),lcs(a,b,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=s1[i-1]+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int sum=0;
        for(int i=0;i<s1.length();i++)
        {
            sum+=s1[i];
        }
        for(int i=0;i<s2.length();i++)
        {
            sum+=s2[i];
        }
        int ans=sum-(2*dp[n][m]);
        return ans;
    }
};