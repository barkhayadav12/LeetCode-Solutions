class Solution {
public:
    bool isPalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s,int i,int j,vector<int>&dp)
    {
        if(i>=j)
        {
            return 0;
        }
        if(isPalindrome(s,i,j)==true)
        {
            return dp[i]=0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(isPalindrome(s,i,k))
            {
                int temp=solve(s,k+1,j,dp)+1;
                ans=min(ans,temp);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int i=0;
        int j=s.length()-1;
        int n=s.length();
        vector<int>dp(n+1,-1);
        return solve(s,i,j,dp);
    }
};