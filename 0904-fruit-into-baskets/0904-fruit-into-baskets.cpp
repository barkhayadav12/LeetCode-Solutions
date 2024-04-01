class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k=2;
        int start=0;
        int end=0;
        int maxi=0;
        unordered_map<int,int>mpp;
        while(end<fruits.size())
        {
           mpp[fruits[end]]++;
           while(mpp.size()>k)
           {
               mpp[fruits[start]]--;
               if(mpp[fruits[start]]==0)
               {
                   mpp.erase(fruits[start]);
               }
               start++;
           }
            if(mpp.size()<=k)
            {
                maxi=max(maxi,end-start+1);
            }
            end++;
        }
        return maxi;
    }
};