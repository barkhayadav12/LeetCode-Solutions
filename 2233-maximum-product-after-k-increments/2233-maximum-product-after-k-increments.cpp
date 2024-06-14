class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(k>0)
        {
            int num=pq.top();
            pq.pop();
            pq.push(num+1);
            k--;
        }
        long long int ans=1;
        int mod = 1e9+7;
        while(!pq.empty())
        {
            int num=pq.top();
            pq.pop();
            ans = ((ans % mod) * (num % mod)) % mod;
        }
        return ans;
    }
};