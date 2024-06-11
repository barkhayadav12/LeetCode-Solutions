class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mpp;
        for(int i=0;i<arr1.size();i++)
        {
            mpp[arr1[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<arr2.size();i++)
        {
            if(mpp.find(arr2[i])!=mpp.end())
            {
                while(mpp[arr2[i]]!=0)
                {
                    ans.push_back(arr2[i]);
                    mpp[arr2[i]]--;
                }
                mpp.erase(arr2[i]);
            }
        }
        if(!mpp.empty())
        {
            for(auto it:mpp)
            {
                int cnt=it.second;
                while(cnt!=0)
                {
                    ans.push_back(it.first);
                    cnt--;
                }
                mpp.erase(it.first);
            }
        }
        return ans;
    }
};