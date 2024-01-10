class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        int ans=0;
        for(auto i:mpp)
        {
            int x=i.second;
            if(x==1)
            {
                ans=i.first;
                break;
            }
        }
        return ans;
    }
};