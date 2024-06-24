class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        pq.push({nums[0],0});
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            while(i-pq.top().second>k)
            {
                pq.pop();
            }
            int temp=max(0,pq.top().first)+nums[i];
            maxi=max(maxi,temp);
            pq.push({temp,i});
        }
        return maxi;
    }
};