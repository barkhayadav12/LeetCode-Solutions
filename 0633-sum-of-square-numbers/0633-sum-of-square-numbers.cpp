class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long b=0;b*b<=c;b++)
        {
            double a=sqrt(c-b*b);
            if(a==(int)a)
            {
                return true;
            }
        }
        return false;
    }
};