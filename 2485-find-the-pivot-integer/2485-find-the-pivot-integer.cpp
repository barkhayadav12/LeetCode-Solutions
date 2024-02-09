class Solution {
public:
    int pivotInteger(int n) {
        int totSum=0;
        for(int i=1;i<=n;i++)
        {
            totSum+=i;
        }
        int ans=-1;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=i;
            if(sum==(totSum-sum+i))
            {
                return i;
            }
        }
        return ans;
    }
};