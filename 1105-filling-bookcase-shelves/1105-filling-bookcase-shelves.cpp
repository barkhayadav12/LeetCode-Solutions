class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>>&books,int ind,int remWidth,int maxHeight,int width)
    {
        int n=books.size();
        if(ind>=n)
        {
            return maxHeight;
        }
        if(dp[ind][remWidth]!=-1)
        {
            return dp[ind][remWidth];
        }
        int keep=INT_MAX;
        int skip=INT_MAX;
        int currWidth=books[ind][0];
        int currHeight=books[ind][1];
        // can keep
        if(currWidth<=remWidth)
        {
            keep=solve(books,ind+1,remWidth-currWidth,max(maxHeight,currHeight),width);
        }
        // skip and place in next shelf
        skip=maxHeight+solve(books,ind+1,width-currWidth,currHeight,width);
        return dp[ind][remWidth]=min(keep,skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        return solve(books,0,shelfWidth,0,shelfWidth);
    }
};