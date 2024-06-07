class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()==1)
        {
            return 1;
        }
        int maxi=0;
        int cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==0)
            {
                continue;
            }
            else if(nums[i]-nums[i-1]==1)
            {
                cnt++;
            }
            else{
                cnt=1;
            }
            maxi=max(cnt,maxi);
        }
        return max(maxi,cnt);
    }
};