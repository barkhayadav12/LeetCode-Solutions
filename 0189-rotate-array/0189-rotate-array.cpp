class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>v;
        if(nums.size()<k)
        {
            k=k%nums.size();
        }
        int index=nums.size()-k;
        for(int i=index;i<nums.size();i++)
        {
            v.push_back(nums[i]);
        }
        for(int i=0;i<index;i++)
        {
            v.push_back(nums[i]);
        }
        for(int i=0;i<v.size();i++)
        {
            nums[i]=v[i];
        }
    }
};