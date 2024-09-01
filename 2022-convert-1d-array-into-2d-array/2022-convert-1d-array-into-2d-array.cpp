class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        if(original.size()!=(m*n))
        {
            return ans;
        }
        int cnt=0;
        for(int i=0;i<original.size();i++)
        {
            cnt++;
            temp.push_back(original[i]);
            if(cnt==n)
            {
                ans.push_back(temp);
                cnt=0;
                temp.clear();
            }
            
        }
        return ans;
    }
};