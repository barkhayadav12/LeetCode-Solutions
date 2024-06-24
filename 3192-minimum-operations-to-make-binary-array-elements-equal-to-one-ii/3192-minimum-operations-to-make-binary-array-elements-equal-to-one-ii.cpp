class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if((nums[i]==1 && flips%2==1) || (nums[i]==0 && flips%2==0))
            {
                flips++;
            }
        }
        return flips;
    }
};