class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       vector<long long int>ans;
        for(int i=0;i<n;i++)
        {
            long long int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                ans.push_back(sum);
            }
        }
        sort(ans.begin(),ans.end());
        long long int res=0;
        int mod=1e9+7;
        for(int i=left-1;i<right;i++)
        {
            res=(res+ans[i])%mod;
        }
        return res;
    }
};