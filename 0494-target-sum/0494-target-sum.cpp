class Solution {
public:
    int solve(vector<int>&arr,int ind,int n,int sum,vector<vector<int>>&dp)
	{
	    // base case
	    if(ind>=n && sum==0)
	    {
	        return 1;
	    }
	    if(ind>=n && sum!=0)
	    {
	        return 0;
	    }
	    if(dp[ind][sum]!=-1)
	    {
	        return dp[ind][sum];
	    }
	    if(sum-arr[ind]>=0)
	    {
	         int pick=solve(arr,ind+1,n,sum-arr[ind],dp);
	         int not_pick=solve(arr,ind+1,n,sum,dp);
	         return dp[ind][sum]=pick+not_pick;
	    }
	    else{
	        int not_pick=solve(arr,ind+1,n,sum,dp);
	        return dp[ind][sum]=not_pick;
	    }
	}
    int findTargetSumWays(vector<int>& nums, int target) {
        target=abs(target);
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int s1=(sum+target)/2;
        if((sum+target)%2==1)
        {
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(s1+1,-1));
        return solve(nums,0,n,s1,dp);
    }
};