class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>isPrime(n,true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i<n;i++)
        {
            if(isPrime[i]==true)
            {
                for(int j=i*2;j<n;j+=i)
                {
                    isPrime[j]=false;
                }
            }
        }
        vector<int>v;
        for(int i=0;i<=isPrime.size()/2;i++)
        {
            if(isPrime[i]==true)
            {
                v.push_back(i);
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<v.size();i++)
        {
            if(isPrime[n-v[i]])
            {
                ans.push_back({v[i],n-v[i]});
            }
        }
        return ans;
    }
};