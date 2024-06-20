class Solution {
public:
    bool isPossible(vector<int>&quantities,int n,long long mid)
    {
        long long cnt=0;
        for(int i=0;i<quantities.size();i++)
        {
            cnt+=(quantities[i]/mid);
            if(quantities[i]%mid!=0)
            {
                cnt++;
            }
        }
        if(cnt<=n)
        {
            return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long l=1;
        long long h=0;
        for(int i=0;i<quantities.size();i++)
        {
            h+=quantities[i];
        }
        long long ans=0;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            if(isPossible(quantities,n,mid)==true)
            {
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};