class Solution {
public:
    int dp[501][501][2];
    int solve(int i,int j,vector<int>&piles, bool isAlice)
    {
        int n=piles.size();
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j][isAlice]!=-1)
        {
            return dp[i][j][isAlice];
        }
        if(isAlice)
        {
            dp[i][j][isAlice]=max(piles[i]+solve(i+1,j,piles,!isAlice),piles[j]+solve(i,j-1,piles,!isAlice));
        }else{
            dp[i][j][isAlice]=max(-piles[i]+solve(i+1,j,piles,!isAlice),-piles[j]+solve(i,j-1,piles,!isAlice));
        }
        return dp[i][j][isAlice];
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,piles.size()-1,piles,true);
        if(ans>0)
        {
            return true;
        }
        return false;
    }
};