class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt_zero=0;
        int left=0;
        int right=0;
        int maxi=0;
        while(right<nums.size())
        {
            if(nums[right]==0)
            {
                cnt_zero++;
            }
            while(cnt_zero>1)
            {
                if(nums[left]==0)
                {
                    cnt_zero--;
                }
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi-1;
    }
};