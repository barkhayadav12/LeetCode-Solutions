class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int cnt_one=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                cnt_one++;
            }
        }
        int max_score=0;
        int cnt_zero=0;
        vector<int>ans;
        for(int i=0;i<=nums.size();i++)
        {
            if(cnt_one+cnt_zero>max_score)
            {
                max_score=cnt_one+cnt_zero;
                ans.clear();
            }
            if(cnt_one+cnt_zero==max_score)
            {
                ans.push_back(i);
            }
            if(i<nums.size())
            {
                if(nums[i]==0)
                {
                    cnt_zero++;
                }
                else{
                    cnt_one--;
                }
            }
        }
        return ans;
    }
};