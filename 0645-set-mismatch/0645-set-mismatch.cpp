class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mpp;
        int sum=nums.size()*(nums.size()+1)/2;
        int actualSum=0;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
            actualSum+=nums[i];
        }
        int diff=abs(sum-actualSum);
        int n=0;
        for(auto i:mpp)
        {
            if(i.second>1)
            {
                n=i.first;
                break;
            }
        }
        int x=0;
        if(sum>actualSum)
        {
            x=diff+n;
        }
        else{
            x=n-diff;
        }
        vector<int>ans;
        ans.push_back(n);
        ans.push_back(x);
        return ans;
        
    }
};