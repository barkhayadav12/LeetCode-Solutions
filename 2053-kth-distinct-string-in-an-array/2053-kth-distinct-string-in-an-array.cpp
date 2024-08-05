class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        vector<string>v;
        for(auto it:mpp)
        {
            if(it.second<=1)
            {
                v.push_back(it.first);
            }
        }
        vector<pair<int,string>>ans;
        for(int i=0;i<v.size();i++)
        {
            string temp=v[i];
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]==temp)
                {
                    ans.push_back({i,arr[i]});
                }
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            if(i==k-1)
            {
                return ans[i].second;
            }
        }
        return "";
    }
};