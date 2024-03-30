class Solution {
public:
    int helper(vector<int>&nums,int k)
    {
        int start=0;
        int end=0;
        int maxi=0;
        int cnt_odd=0;
        while(end<nums.size())
        {
            if((nums[end])&1)
            {
                cnt_odd++;
            }
            while(cnt_odd>k)
            {
                if((nums[start])&1)
                {
                    cnt_odd--;
                }
                start++;
            }
            maxi+=end-start+1;
            end++;
        }
        return maxi;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};