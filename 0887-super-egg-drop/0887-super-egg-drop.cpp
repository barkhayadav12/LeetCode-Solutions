class Solution {
public:
    int solve(int k,int n,vector<vector<int>>&dp)
    {
        // base case 
        if(n==0 || n==1)
        {
            return n;
        }
        if(k==1)
        {
            return n;
        }
        if(dp[k][n]!=-1)
        {
            return dp[k][n];
        }
        int ans=INT_MAX;
        int lo=1,hi=n,temp=0;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2; //k
            int left=solve(k-1,mid-1,dp); //if break kr gayi, toh neeche ke floors mein dekhenge
            int right=solve(k,n-mid,dp); //if break nhi kri, toh upar dekhenge
            temp=1+max(left,right);
            if(left<right)
            {
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
            ans=min(ans,temp);
        }
        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};