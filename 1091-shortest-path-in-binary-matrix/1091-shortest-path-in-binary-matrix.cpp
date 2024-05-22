class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        if(grid[0][0]==1 || grid[n][m]==1)
        {
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int delRow[8]={0,0,-1,1,-1,-1,1,1};
        int delCol[8] = {1,-1,0,0,-1,1,1,-1}; 
        while(!q.empty() && !grid[n][m])
        {
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            for(int i=0;i<8;i++)
            {
                int newr=r+delRow[i];
                int newc=c+delCol[i];
        if(newr>=0 && newr<=n && newc>=0 && newc<=m && grid[newr][newc]==0)
        {
            grid[newr][newc]=grid[r][c]+1;
            q.push({newr,newc});
        }
            }
        }
        return grid[n][m]?grid[n][m]:-1;
    }
};