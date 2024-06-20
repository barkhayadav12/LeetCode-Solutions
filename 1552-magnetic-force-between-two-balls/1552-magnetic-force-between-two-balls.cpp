class Solution {
public:
    bool isPossible(vector<int>&position, int m,int x)
    {
        int curr=position[0];
        int ans=1;
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-curr>=x)
            {
                ans++;
                curr=position[i];
                if(ans==m)
                {
                    return true;
                }
            }
        }
        if(ans<m)
        {
            return false;
        }
        return true;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int l=1,h=position[n-1];
        int ans=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(isPossible(position,m,mid)==true)
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