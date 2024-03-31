class Solution {
public:
    int helper(vector<int>&nums,int goal)
    {
        int i=0;
        int end=0;
        int cnt=0;
        int sum=0;
        if(goal<0)
        {
            return 0;
        }
        for(int j=0;j<nums.size();j++)
        {
            goal-=nums[j];
            while(goal<0)
            {
                goal+=nums[i++];
            }
            cnt+=(j-i+1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1);
    }
};