class Solution {
public:
    int helper(vector<int>&nums,int k)
    {
        int start=0;
        int end=0;
        map<int,int>mpp;
        int cnt=0;
        int n=nums.size();
        while(end<n)
        {
            mpp[nums[end]]++;
            while(mpp.size()>k)
            {
                mpp[nums[start]]--;
                if(mpp[nums[start]]==0)
                {
                    mpp.erase(nums[start]);
                }
                start++;
            }
            cnt+=end-start+1;
            end=end+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};