class Solution {
    private:
    void dfs(int row,int col,int color,int delRow[],int delCol[],vector<vector<int>>&image,vector<vector<int>>&ans,int initialColor)
    {
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==initialColor)
            {
                dfs(nrow,ncol,color,delRow,delCol,image,ans,initialColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        vector<vector<int>>ans=image;
         int initialColor=image[sr][sc];
         dfs(sr,sc,color,delRow,delCol,image,ans,initialColor);
        return ans;
    }
};