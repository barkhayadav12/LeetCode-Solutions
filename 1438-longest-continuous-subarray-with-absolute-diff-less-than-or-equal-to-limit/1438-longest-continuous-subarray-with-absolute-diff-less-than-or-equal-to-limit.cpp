class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0,j=0;
        multiset<int>s;
        int n=nums.size();
        int ans=0;
        while(j<n)
        {
            s.insert(nums[j]);
            int diff=*s.rbegin()-*s.begin();
            if(diff>limit)
            {
                auto it=s.find(nums[i]);
                s.erase(it);
                i++;
                diff=*s.rbegin()-*s.begin();
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};