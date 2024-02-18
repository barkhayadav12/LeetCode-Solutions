class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int a=nums[i];
            for(int j=i;j<nums.size();j++)
            {
                a=gcd(a,nums[j]);
                if(a==k)
                {
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};