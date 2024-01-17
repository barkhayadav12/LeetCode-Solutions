class Solution {
public:
    map<int,int>mpp;
    bool uniqueOccurrences(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        vector<int>v;
        for(auto i:mpp)
        {
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1])
            {
                return false;
            }
        }
        return true;
    }
};