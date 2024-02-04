class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target=abs(target);
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int sum_one=(target+sum)/2;
        if(sum-target<0 || (sum-target)%2!=0)
        {
            return 0;
        }
        int dp[n+1][sum_one+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum_one;j++)
            {
                if(i==0)
                {
                    dp[i][j]=0;
                }
                if(j==0)
                {
                    dp[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum_one;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
                else if(nums[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum_one];
    }
};