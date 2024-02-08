class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
       int n=nums.size();
        vector<int>prefix_sum;
        prefix_sum=nums;
        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        vector<int>leftArray;
        leftArray=nums;
        leftArray[0]=0;
        for(int i=1;i<n;i++)
        {
            leftArray[i]=prefix_sum[i-1];
        }
        vector<int>rightArray;
        rightArray=nums;
        for(int i=0;i<n;i++)
        {
            rightArray[i]=prefix_sum[n-1]-prefix_sum[i];
        }
         vector<int>ansArray;
        ansArray=nums;
        for(int i=0;i<n;i++)
        {
            ansArray[i]=abs(leftArray[i]-rightArray[i]);
        }
        return ansArray;
    }
};