class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int>mpp;
        int m=roads.size();
        for(int i=0;i<m;i++)
        {
            mpp[roads[i][0]]++;
            mpp[roads[i][1]]++;
        }
        vector<pair<int, int>> vec(mpp.begin(), mpp.end());
        sort(vec.begin(), vec.end(), 
         [](const pair<int, int> &a, const pair<int, int> &b) {
             return a.second > b.second;
         });
        long long ans=0;
        for(auto it:vec)
        {
            ans+=(long long)(n)*(it.second);
            n--;
        }
        return ans;
    }
};