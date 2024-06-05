class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mpp[nums[i][j]]++;
            }
        }
        vector<int>ans;
        for(auto it:mpp)
        {
            if(it.second==nums.size())
            {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};