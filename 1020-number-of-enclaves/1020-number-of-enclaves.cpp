class Solution {
    private:
    private:
    void dfs(vector<vector<int>>&grid, vector<vector<int>>&vis,int row,int col,int delRow[],int delCol[],int n,int m)
    {
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(grid,vis,nrow,ncol,delRow,delCol,n,m);
            }
        }
        
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1 && !vis[i][j])
                    {
                        dfs(grid,vis,i,j,delRow,delCol,n,m);
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] ==1 && !vis[i][j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};