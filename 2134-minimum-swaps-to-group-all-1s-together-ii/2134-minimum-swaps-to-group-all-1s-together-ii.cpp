class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt_one=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            cnt_one+=nums[i];
        }
        if(cnt_one==0 || cnt_one==n)
        {
            return 0;
        }
        int i=0,j=0;
        int sum=0;
        int mini=INT_MAX;
        int k=cnt_one;
        while(j<2*n)
        {
            sum+=nums[j%n];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                mini=min(mini,cnt_one-sum);
                sum-=nums[i%n];
                i++;
                j++;
            }
        }
        return mini;
    }
};