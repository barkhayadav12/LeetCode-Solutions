class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>v;
        for(int i=0,j=n;j<nums.size();i++,j++)
        {
            v.push_back(nums[i]);
            v.push_back(nums[j]);
        }
        return v;
    }
};