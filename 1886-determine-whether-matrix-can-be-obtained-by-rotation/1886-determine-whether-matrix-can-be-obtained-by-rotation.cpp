class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target)
        {
            return true;
        }
        int degree=3;
        while(degree--){
        reverse(mat.begin(),mat.end());
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
        if(mat==target)
        {
            return true;
        }
        }
        return false;
    }
};