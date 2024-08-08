class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>res;
        int steps=0;
        int d=0;
        res.push_back({rStart,cStart});
        while(res.size()<rows*cols)
        {
            if(d==0 || d==2)
            {
                steps++;
            }
            for(int i=0;i<steps;i++)
            {
                rStart+=dir[d][0];
                cStart+=dir[d][1];
                if(rStart>=0 && cStart>=0 && rStart<rows && cStart<cols)
                {
                    res.push_back({rStart,cStart});
                }
            }
            d=(d+1)%4;
        }
        return res;
    }
};