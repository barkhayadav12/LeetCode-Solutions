class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>out(n+1);
        vector<int>in(n+1);
        for(int i=0;i<trust.size();i++)
        {
            out[trust[i][1]]++;
            in[trust[i][0]]++; 
        }
        for(int i=1;i<=n;i++)
        {
            if(out[i]==n-1 && in[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
};