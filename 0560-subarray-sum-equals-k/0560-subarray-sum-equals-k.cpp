class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int preSum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            preSum+=nums[i];
            if(mpp.find(preSum-k)!=mpp.end())
            {
                cnt+=mpp[preSum-k];
            }
            mpp[preSum]++;
        }
        return cnt;
    }
};