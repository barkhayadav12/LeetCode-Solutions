class Solution {
public:
    int fn(int i,int j,vector<vector<char>>&matrix,int &maxi,vector<vector<int>>&dp)
    {
        if(i>=matrix.size() || j>=matrix[0].size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right=fn(i+1,j,matrix,maxi,dp);
        int down=fn(i,j+1,matrix,maxi,dp);
        int diagonal=fn(i+1,j+1,matrix,maxi,dp);
        if(matrix[i][j]=='1')
        {
            dp[i][j]=1+min(right,min(down,diagonal));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int maxi=0;
        int s=fn(0,0,matrix,maxi,dp);
        return maxi*maxi;
    }
};