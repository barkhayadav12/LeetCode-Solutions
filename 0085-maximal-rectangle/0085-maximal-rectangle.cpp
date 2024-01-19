class Solution {
public:
    int largestRectangleArea(vector<int>&v) {
        stack<pair<int,int>>nsl;
        int pseudoIndex=-1;
        vector<int>left;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(nsl.empty())
            {
                left.push_back(pseudoIndex);
            }
            else if(nsl.size()>0 && nsl.top().first<v[i])
            {
                left.push_back(nsl.top().second);
            }
            else if(nsl.size()>0 && nsl.top().first>=v[i])
            {
                while(nsl.size()>0 && nsl.top().first>=v[i])
                {
                    nsl.pop();
                }
                if(nsl.size()==0)
                {
                    left.push_back(pseudoIndex);
                }
                else{
                    left.push_back(nsl.top().second);
                }
            }
            nsl.push({v[i],i});
        }
        stack<pair<int,int>>nsr;
        pseudoIndex=n;
        vector<int>right;
        for(int i=n-1;i>=0;i--)
        {
            if(nsr.empty())
            {
                right.push_back(pseudoIndex);
            }
            else if(nsr.size()>0 && nsr.top().first<v[i])
            {
                right.push_back(nsr.top().second);
            }
            else if(nsr.size()>0 && nsr.top().first>=v[i])
            {
                while(nsr.size()>0 && nsr.top().first>=v[i])
                {
                    nsr.pop();
                }
                if(nsr.size()==0)
                {
                    right.push_back(pseudoIndex);
                }
                else{
                    right.push_back(nsr.top().second);
                }
            }
             nsr.push({v[i],i});
        }
        reverse(right.begin(),right.end());
        int width[n];
        for(int i=0;i<n;i++)
        {
            width[i]=(right[i]-left[i]-1);
        }
        int area=0;
        for(int i=0;i<n;i++)
        {
            area=max(area,width[i]*v[i]);
        }
        return area;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>v(col,0);
        int mx=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]-48==0)
                {
                    v[j]=0;
                }
                else{
                    v[j]=v[j]+(matrix[i][j]-48);
                }
            }
            mx=max(mx,largestRectangleArea(v));
           
        }
        return mx;
    }
};