class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        int n=chalk.size();
        for(int i=0;i<n;i++)
        {
            sum+=(long long)(chalk[i]);
        }
        k=(long long)k%sum;
        for(int i=0;i<n;i++)
        {
            if(k-chalk[i]<0)
            {
                return i;
            }
            k-=chalk[i];
        }
        return 1;
    }
};