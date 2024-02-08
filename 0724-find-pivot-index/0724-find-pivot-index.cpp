class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>prefix_sum;
        prefix_sum=nums;
        prefix_sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        int n=prefix_sum.size()-1;
        int ans=-1;
        int rightSum=0;
        int leftSum=0;
        for(int i=0;i<prefix_sum.size();i++)
        {
            if(i==0)
            {
                leftSum=0;
            }
            else{
                leftSum=prefix_sum[i-1];
            }
            if(i==n)
            {
                rightSum=0;
            }
            else{
                rightSum=prefix_sum[n]-prefix_sum[i];
            }
            if(leftSum==rightSum)
            {
                ans=i;
                break;
            }
            
        }
        return ans;
    }
};