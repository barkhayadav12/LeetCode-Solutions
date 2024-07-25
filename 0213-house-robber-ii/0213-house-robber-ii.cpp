// class Solution {
// public:
//      int fn(int ind,vector<int>&nums,vector<int>&dp)
//      {
//         if(ind<0)
//         {
//             return 0;
//         }
//         if(dp[ind]!=-1)
//         {
//             return dp[ind];
//         }
//         int pick=nums[ind]+fn(ind-2,nums,dp);
//         int not_pick=0+fn(ind-1,nums,dp);
//         return dp[ind]=max(pick,not_pick);
//     }
//     int rob(vector<int>& nums) {
//         if(nums.size()==1)
//         {
//             return nums[0];
//         }
//         int n=nums.size();
//         vector<int>dp(n-1,-1);
//         vector<int>pd(n-1,-1);
//         vector<int>temp_one;
//         vector<int>temp_two;
//         for(int i=0;i<n;i++)
//         {
//             if(i!=0)
//             {
//                 temp_one.push_back(nums[i]);
//             }
//             if(i!=n-1)
//             {
//                 temp_two.push_back(nums[i]);
//             }
//         }
//         int ans_one=fn(n-2,temp_one,dp);
//         int ans_two=fn(n-2,temp_two,pd);
//         return max(ans_one,ans_two);
//     }
// };
class Solution {
public:
    int solve(vector<int>&v,vector<int>&dp,int ind,int n)
    {
        if(ind>=n)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int pick=v[ind]+solve(v,dp,ind+2,n);
        int not_pick=0+solve(v,dp,ind+1,n);
        return dp[ind]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()==1)
        {
            return nums[0];
        }
        int n=nums.size();
        vector<int>vec_one;
        vector<int>vec_two;
        for(int i=0;i<n;i++)
        {
            if(i!=n-1)
            {
                vec_one.push_back(nums[i]);
            }
            if(i!=0)
            {
                vec_two.push_back(nums[i]);
            }
        }
        vector<int>dp_one(n,-1);
        vector<int>dp_two(n,-1);
        return max(solve(vec_one,dp_one,0,n-1),solve(vec_two,dp_two,0,n-1));
    }
};