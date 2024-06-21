class Solution {
public:
    long long isPossible(vector<int>&ranks,long long mid,int cars)
    {
        long long cnt=0;
        long long ans=0;
        for(int i=0;i<ranks.size();i++)
        {
            cnt+=sqrt(mid/ranks[i]);
        }
        if(cnt>=cars)
        {
            return true;
        }
        else{
            return false;
        }
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1;
        long long h= (long long)cars * (long long)cars * 100;
        long long ans=0;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            if(isPossible(ranks,mid,cars)==true)
            {
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};