class Solution {
public:

    int solve(int a,int b)
    {
        int reqd_one=1;
        int reqd_two=2;
        int cnt=0;
        if(a>=reqd_one)
        {
            cnt++;
            reqd_one=reqd_one+2;
            a-=1;
        }
        else{
            return cnt;
        }
        if(b>=reqd_two)
        {
            cnt++;
            reqd_two=reqd_two+2;
            b-=2;
        }
        else{
            return cnt;
        }
        bool flag=true;
        while(1)
        {
            if(reqd_one<=a)
            {
                cnt++;
                a-=reqd_one;
                reqd_one+=2;
            }
            else{
                break;
            }
            if(reqd_two<=b)
            {
                cnt++;
                b-=reqd_two;
                reqd_two+=2;
            }
            else{
                break;
            }
        }
        return cnt;
    }

    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red,blue),solve(blue,red));
    }
};