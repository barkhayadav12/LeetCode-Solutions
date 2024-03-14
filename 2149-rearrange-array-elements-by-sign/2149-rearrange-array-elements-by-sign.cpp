class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos_num;
        vector<int>neg_num;
        vector<int>whole_array;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                neg_num.push_back(nums[i]);
            }
            else{
                pos_num.push_back(nums[i]);
            }
        }
        for(int i=0;i<pos_num.size();i++)
        {
            whole_array.push_back(pos_num[i]);
            whole_array.push_back(neg_num[i]);

        }
        return whole_array;
    }
};