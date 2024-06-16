class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        long long maxSum=1;
        sort(coins.begin(),coins.end());
        for(int i=0;i<coins.size();i++)
        {
            if(coins[i]>maxSum)
            {
                break;
            }
            else{
                maxSum+=coins[i];
            }
        }
        return maxSum;
    }
};