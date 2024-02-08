class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=((sum+nums[i])%k+k)%k;
            mpp[sum]++;
            if(mpp[sum]>1)
            {
                ans+=mpp[sum]-1;
            }
        }
        return ans;
        
    }
};