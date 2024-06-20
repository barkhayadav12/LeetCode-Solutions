class Solution {
public:
    bool isPossible(vector<int>&nums,int k,int x)
    {
        int cnt=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>x)
            {
                cnt++;
                sum=nums[i];
            }
        }
        if(cnt<=k)
        {
            return true;
        }else{
            return false;
        }
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element (nums.begin(), nums.end());
        int h=accumulate(nums.begin(), nums.end(), 0);
        int ans=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(isPossible(nums,k,mid)==true)
            {
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};