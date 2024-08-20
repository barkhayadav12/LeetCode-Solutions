class Solution {
public:
    int dp[101][101][2];
    int solve(int ind,int m,bool isAlice,vector<int>&piles)
    {
        int n=piles.size();
        if(ind>=n)
        {
            return 0;
        }
        if(dp[ind][m][isAlice]!=-1)
        {
            return dp[ind][m][isAlice];
        }
        int res=(isAlice)? INT_MIN : INT_MAX;
        int stones=0;
        for(int x=1;x<=min(2*m,n-ind);x++)
        {
            stones+=piles[ind+x-1];
            if(isAlice)
            {
                res=max(res,stones+solve(ind+x,max(m,x),!isAlice,piles));
            }
            else{
                res=min(res,solve(ind+x,max(m,x),!isAlice,piles));
            }
        }
        return dp[ind][m][isAlice]=res;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,1,true,piles);
        return ans;
    }
};