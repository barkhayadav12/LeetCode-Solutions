class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                pos.push_back(nums[i]);
            }
        }
        vector<int>neg;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                neg.push_back(nums[i]);
            }
        }
        vector<int>v;
        for(int i=0;i<pos.size();i++)
        {
            v.push_back(pos[i]);
            v.push_back(neg[i]);
        }
        return v;
        
    }
};