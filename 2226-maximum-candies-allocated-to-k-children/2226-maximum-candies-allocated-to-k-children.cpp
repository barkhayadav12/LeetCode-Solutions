class Solution {
public:
    bool isPossible(vector<int>&candies,long long k,long long mid)
    {
        long long cnt=0;
        for(int i=0;i<candies.size();i++)
        {
            cnt+=(candies[i]/mid);
        }
        if(cnt>=k)
        {
            return true;
        }else{
            return false;
        }
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long l=1;
        long long h=0;
        for(int i=0;i<candies.size();i++)
        {
            h+=candies[i];
        }
        long long ans=0;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            if(isPossible(candies,k,mid)==true)
            {
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};