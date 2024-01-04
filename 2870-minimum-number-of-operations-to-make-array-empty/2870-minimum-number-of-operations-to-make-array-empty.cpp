class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        int cnt=0;
        for(auto i:mpp)
        {
            if((i.second)==1)
            {
                return -1;
            }
            cnt+=(i.second)/3;
            if(i.second%3)
            {
                cnt++;
            }
            
        }
        return cnt;
        
    }
};