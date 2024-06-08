class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int preSum=0;
        for(int i=0;i<nums.size();i++)
        {
            preSum=(preSum+nums[i])%k;
            if(mpp.find(preSum)!=mpp.end())
            {
                if(i-mpp[preSum]>1)
                {
                    return true;
                }
            }
            else{
                mpp[preSum]=i;
            }
        }
        return false;
        
    }
};