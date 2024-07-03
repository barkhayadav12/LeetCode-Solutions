class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<=4)
        {
            return 0;
        }
        //4 ways
        //remove 3 largest in the array
        int num1=nums[n-4]-nums[0];
        //remove first 3 smallest 
        int num2=nums[n-1]-nums[3];
        //remove 1 largest and 2 smallest
        int num3=nums[n-2]-nums[2];
        //remove 1 smallest and 2 largest
        int num4=nums[n-3]-nums[1];
        return min(num1,min(num2,min(num3,num4)));
        
    }
};