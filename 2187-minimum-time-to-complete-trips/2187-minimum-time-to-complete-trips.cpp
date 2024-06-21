class Solution {
public:
    bool isPossible(vector<int>& time,int totalTrips,long long mid)
    {
        long long cnt=0;
        for(int i=0;i<time.size();i++)
        {
            cnt+=(mid/time[i]);
        }
        if(cnt>=totalTrips)
        {
            return true;
        }else{
            return false;
        }
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo=1;
        long long hi=0;
        for(int i=0;i<time.size();i++)
        {
            hi+=time[i];
        }
        hi*=totalTrips;
        long long ans=0;
        while(lo<=hi)
        {
            long long mid=lo+(hi-lo)/2;
            if(isPossible(time,totalTrips,mid)==true)
            {
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};