class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%3!=0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};