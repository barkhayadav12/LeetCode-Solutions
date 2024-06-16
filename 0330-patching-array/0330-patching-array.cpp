class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxSum=0;
        int cnt=0;
        int i=0;
        while(maxSum<n)
        {
            if(i<nums.size() && nums[i]<=maxSum+1)
            {
                maxSum+=nums[i];
                i++;
            }
            else{
                maxSum+=maxSum+1;
                cnt++;
            }
        }
        return cnt;
    }
};