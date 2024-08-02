class Solution {
public:
    int solve(vector<int>&days,vector<int>&costs,int i,int valid,vector<vector<int>>&dp)
    {
       int n=days.size();
       if(i>=n)
       {
           return 0;
       }
        if(dp[i][valid]!=-1)
        {
            return dp[i][valid];
        }
       if(days[i]<=valid)
       {
           return dp[i][valid]=solve(days,costs,i+1,valid,dp);
       }
       else{
           int day1=costs[0]+solve(days,costs,i+1,days[i],dp);
           int day7=costs[1]+solve(days,costs,i+1,days[i]+6,dp);
           int day30=costs[2]+solve(days,costs,i+1,days[i]+29,dp);
           return dp[i][valid]=min(day1,min(day7,day30));
       }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int max_validity = days[n-1] + 30;
        vector<vector<int>> dp(n, vector<int>(max_validity, -1));
        return solve(days,costs,0,0,dp);
    }
};