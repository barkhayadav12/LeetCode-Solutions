class Solution {
public:
    int fn(int curr,int target,int last_copy,vector<vector<int>>&dp)
    {
        if(curr==target)
        {
            return 0;
        }
        if(curr>target)
        {
            return 1e9;
        }
        if(dp[curr][last_copy]!=-1)
        {
            return dp[curr][last_copy];
        }
        if(curr==last_copy)
        {
            return dp[curr][last_copy]=1+fn(curr+last_copy,target,last_copy,dp);
        }else{
        return dp[curr][last_copy]=min(1+fn(curr+last_copy,target,last_copy,dp),1+fn(curr,target,curr,dp));
        }
    }
    int minSteps(int n) {
        if(n==1)
        {
            return 0;
        }
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return fn(1, n, 1, dp) + 1;
    }
};