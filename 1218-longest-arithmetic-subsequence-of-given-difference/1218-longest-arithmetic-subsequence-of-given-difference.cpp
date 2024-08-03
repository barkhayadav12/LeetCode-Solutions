class Solution {
public:
    int solve(vector<int>&arr, int diff,int prev,int curr,vector<vector<int>>&dp)
    {
        int n=arr.size();
        if(curr>=n)
        {
            return 0;
        }
        if(dp[prev+1][curr]!=-1)
        {
            return dp[prev+1][curr];
        }
        int not_take=0+solve(arr,diff,prev,curr+1,dp);
        int take=INT_MIN;
        // can pick
        if(prev==-1 || arr[curr]-arr[prev]==diff)
        {
            take=1+solve(arr,diff,curr,curr+1,dp);
        }
        return dp[prev+1][curr]=max(not_take,take);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        int ans=1;
        for(int i=0;i<n;i++)
        {
            if(mpp.find(arr[i]-difference)!=mpp.end())
            {
                mpp[arr[i]]=1+mpp[arr[i]-difference];
            }
            else{
                mpp[arr[i]]=1;
            }
            ans=max(ans,mpp[arr[i]]);
        }
        return ans;
    }
};