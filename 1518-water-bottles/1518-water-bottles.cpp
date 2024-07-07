class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int tot=numBottles;
        int ans=numBottles;
        while(tot>=numExchange)
        {
            int initial=tot/numExchange;
            int rem=tot%numExchange;
            ans+=initial;
            tot=initial+rem;
        }
        return ans;
    }
};