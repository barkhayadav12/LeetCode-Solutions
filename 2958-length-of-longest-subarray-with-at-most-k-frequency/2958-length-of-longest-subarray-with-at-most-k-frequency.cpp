class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int>mpp;
        int j=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
            while(mpp[nums[i]]>k)
                {
                    mpp[nums[j]]--;
                    j++;
                }
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};