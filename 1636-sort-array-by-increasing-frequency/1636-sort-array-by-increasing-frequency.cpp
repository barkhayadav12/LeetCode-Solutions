
class Solution {
public:
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2)
     {
        if(p1.first==p2.first)
        {
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto i:mpp)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<v.size();i++)
        {
            int x=v[i].first;
            int y=v[i].second;
            for(int i=0;i<x;i++)
            {
                ans.push_back(y);
            }
        }
        return ans;
    }
};