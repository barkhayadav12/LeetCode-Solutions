class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        priority_queue<int>maxh;
        map<int,int>mpp;
        mpp[nums[0]]++;
        maxh.push(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(mpp.find(nums[i])!=mpp.end())
            {
                int num=maxh.top();
                maxh.pop();
                cnt+=abs(num-nums[i])+1;
                maxh.push(num+1);
                mpp[num+1]++;
            }
            mpp[nums[i]]++;
            maxh.push(nums[i]);
        }
        return cnt;
    }
};