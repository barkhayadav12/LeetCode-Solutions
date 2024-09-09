class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();
       vector<int>ans;
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=m-1;
        int idx=0;
        while(top<=bottom && left<=right)
        {
            if(idx==0)
            {
                for(int i=left;i<=right;i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            if(idx==1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            if(idx==2)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(idx==3)
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            idx=(idx+1)%4;
        }
        return ans;
    }
};