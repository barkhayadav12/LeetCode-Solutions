class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=0;
        int overall_max=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            max_sum+=nums[i];
            if(max_sum>overall_max)
            {
                overall_max=max_sum;
            }
            if(max_sum<0)
            {
                max_sum=0;
            }
        }
        return overall_max;
    }
};