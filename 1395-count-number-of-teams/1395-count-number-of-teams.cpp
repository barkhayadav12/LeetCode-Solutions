class Solution {
public:
    int dp_in[1001][1001][4];
    int dp_dec[1001][1001][4];
    // increasing
    int fn_in(vector<int>&rating,int currInd,int prevInd,int k)
    {
        int n=rating.size();
        // base case
        if(k==0)
        {
            return 1;
        }
        if(currInd>=n)
        {
            return 0;
        }
        if(dp_in[currInd][prevInd+1][k]!=-1)
        {
            return dp_in[currInd][prevInd+1][k];
        }
        int not_pick=fn_in(rating,currInd+1,prevInd,k);
        int pick=0;
        // checking if we can pick it or not
        if(prevInd==-1 || rating[currInd]>rating[prevInd])
        {
            pick=fn_in(rating,currInd+1,currInd,k-1);
        }
        return dp_in[currInd][prevInd+1][k]=not_pick+pick;
    }
    // decreasing
    int fn_dec(vector<int>&rating,int currInd,int prevInd,int k)
    {
        int n=rating.size();
        // base case
        if(k==0)
        {
            return 1;
        }
        if(currInd>=n)
        {
            return 0;
        }
        if(dp_dec[currInd][prevInd+1][k]!=-1)
        {
            return dp_dec[currInd][prevInd+1][k];
        }
        int not_pick=fn_dec(rating,currInd+1,prevInd,k);
        int pick=0;
         // checking if we can pick it or not
        if(prevInd==-1 || rating[currInd]<rating[prevInd])
        {
            pick=fn_dec(rating,currInd+1,currInd,k-1);
        }
        return dp_dec[currInd][prevInd+1][k]=not_pick+pick;
    }
    int numTeams(vector<int>& rating) {
        memset(dp_in,-1,sizeof(dp_in));
        memset(dp_dec,-1,sizeof(dp_dec));
        return fn_in(rating,0,-1,3)+fn_dec(rating,0,-1,3);
    }
};