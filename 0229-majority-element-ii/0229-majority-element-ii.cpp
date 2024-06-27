class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        int freq=floor(n/3);
        vector<int>ans;
        for(auto it:mpp)
        {
            if(it.second>freq)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};