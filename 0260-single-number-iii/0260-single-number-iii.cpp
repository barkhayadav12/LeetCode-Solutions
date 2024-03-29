class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        vector<int>v;
        for(auto it:mpp)
        {
            if(it.second==1)
            {
                v.push_back(it.first);
            }
        }
        return v;
        
    }
};