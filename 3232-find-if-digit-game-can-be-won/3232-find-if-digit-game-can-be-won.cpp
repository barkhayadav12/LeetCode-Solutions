class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum_one=0;
        int sum_two=0;
        for(auto it:nums)
        {
            if(it>=10)
            {
                sum_two+=it;
            }
            else{
                sum_one+=it;
            }
        }
        if(sum_one> sum_two || sum_two>sum_one)
        {
            return true;
        }
        return false;
    }
};