class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int tot_sum=accumulate(rolls.begin(),rolls.end(),0);
        int num=rolls.size()+n;
        int missing=(mean*num)-tot_sum;
        if(missing<n || missing>6*n)
        {
            return {};
        }
        int x=(missing/n);
        vector<int>ans(n,x);
        int rem=(missing%n);
        for(int i=0;i<rem;i++)
        {
            ans[i]+=1;
        }
        return ans;
    }
};