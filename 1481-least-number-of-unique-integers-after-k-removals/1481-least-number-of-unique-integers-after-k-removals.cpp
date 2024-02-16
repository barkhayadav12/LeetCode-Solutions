class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        vector<int>v;
        for(auto i:mpp)
        {
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(k>v[i])
            {
                k-=v[i];
                v[i]=0;
            }
            else{
                v[i]-=k;
                k=0;
            }
        }
        int cnt=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};