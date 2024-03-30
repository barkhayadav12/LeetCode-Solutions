class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int lsum=0;
       int rsum=0;
       int maxSum=0;
       for(int i=0;i<k;i++)
       {
           lsum+=cardPoints[i];
       }
       int right=cardPoints.size()-1;
       maxSum=lsum;
       for(int i=k-1;i>=0;i--)
       {
           lsum-=cardPoints[i];
           rsum+=cardPoints[right];
           right--;
           maxSum=max(maxSum,lsum+rsum);
       }
       return maxSum;
    }
};