class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int tot_sum=0;
        int n=customers.size();
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                tot_sum+=customers[i];
            }
        }
        int i=0;
        int j=0;
        int maxi=0;
        int k=minutes;
        while(j<n)
        {
            if(grumpy[j]==1)
            {
                tot_sum+=customers[j];
            }
            if((j-i+1)<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                maxi=max(maxi,tot_sum);
                if(grumpy[i]==1)
                {
                     tot_sum-=customers[i];
                }
                i++;
                j++;
            }
        }
        return maxi;
    }
};