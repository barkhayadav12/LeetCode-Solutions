class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
        }
        int lastInd=0;
        int maxi=1;
        for(int ind=0;ind<n;ind++)
        {
            for(int prev=0;prev<ind;prev++)
            {
                if((nums[ind]%nums[prev]==0) && 1+dp[prev]>dp[ind])
                {
                    hash[ind]=prev;
                    dp[ind]=1+dp[prev];
                }
            }
            if(dp[ind]>maxi)
            {
                maxi=dp[ind];
                lastInd=ind;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd)
        {
            lastInd=hash[lastInd];
            temp.push_back(nums[lastInd]);
        }
        return temp;
    }
};