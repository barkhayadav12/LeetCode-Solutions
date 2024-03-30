class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int end=0;
        int maxi=0;
        int cnt_zero=0;
        while(end<nums.size())
        {
           if(nums[end]==0)
           {
               cnt_zero++;
           }
           while(cnt_zero>k)
           {
               if(nums[start]==0)
               {
                   cnt_zero--;
               }
               start++;
           }
            maxi=max(maxi,end-start+1);
            end++;
            
        }
        return maxi;
    }
};