class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int>mini;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            int temp=INT_MAX;
            for(int j=0;j<m;j++)
            {
                temp=min(temp,matrix[i][j]);
            }
            mini.insert(temp);
        }
        vector<int>ans;
        for(int j=0;j<m;j++)
        {
            int temp=INT_MIN;
            for(int i=0;i<n;i++)
            {
                temp=max(temp,matrix[i][j]);
            }
            if(mini.find(temp)!=mini.end())
            {
                ans.push_back(temp);
            }
        }
        return ans;
    }
};