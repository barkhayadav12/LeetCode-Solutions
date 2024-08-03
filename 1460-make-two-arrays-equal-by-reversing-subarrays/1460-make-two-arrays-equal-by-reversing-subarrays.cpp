class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>mpp;
        int n=target.size();
        for(int i=0;i<n;i++)
        {
            mpp[target[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mpp.find(arr[i])!=mpp.end())
               {
                   mpp[arr[i]]--;
                   if(mpp[arr[i]]==0)
                   {
                       mpp.erase(arr[i]);
                   }
               }
               else{
                   return false;
               }
        }
        if(mpp.empty())
               {
                   return true;
               }
               return false;
    }
};