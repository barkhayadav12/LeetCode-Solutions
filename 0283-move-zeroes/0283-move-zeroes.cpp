class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int cnt_zero=0;
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                v.push_back(nums[i]);
            }
            else if(nums[i]==0)
            {
                cnt_zero++;
            }
        }
        for(int i=1;i<=cnt_zero;i++)
        {
            v.push_back(0);
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=v[i];
        }
    }
};