class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        if(nums.size()==1)
        {
            return 0;
        }
        for(int i=1;i<nums.size();i++)
        {
            int f=nums[i-1];
            int s=nums[i];
            if(s>f)
            {
                continue;
            }
            else{
                while(nums[i-1]>nums[i])
                {
                    nums[i]++;
                    cnt++;
                }
                nums[i]+=1;
                cnt+=1;
            }
        }
        return cnt;
    }
};