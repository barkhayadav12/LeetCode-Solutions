class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
       int num_of_flip=0;
       int ans=0;
       for(int i=0;i<nums.size();i++)
       {
           if(i>=k)
           {
               if(nums[i-k]>1)
               {
                   nums[i-k]-=2;
                   num_of_flip-=1;
               }
           }
           if((nums[i]==1 && num_of_flip%2==1) || (nums[i]==0 && num_of_flip%2==0))
           {
               if(i+k>nums.size())
               {
                   return -1;
               }
               nums[i]+=2;
               ans++;
               num_of_flip++;
           }
       }
       return ans;
    }
};