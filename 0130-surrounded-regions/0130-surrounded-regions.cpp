class Solution {
    private:
    void dfs(vector<vector<char>>&board, vector<vector<int>>&vis,int row,int col,int delRow[],int delCol[],int n,int m)
    {
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O')
            {
                dfs(board,vis,nrow,ncol,delRow,delCol,n,m);
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(board[i][j]=='O' && !vis[i][j])
                    {
                        dfs(board,vis,i,j,delRow,delCol,n,m);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
        
    }
};