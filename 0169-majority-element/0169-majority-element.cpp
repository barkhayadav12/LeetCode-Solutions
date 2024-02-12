class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num=ceil(nums.size()/2);
        map<int,int>mpp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        for(auto i:mpp)
        {
            if(i.second>num)
            {
                ans=i.first;
                break;
            }
        }
        return ans;
    }
};