class Solution {
public:
    vector<int> evenOddBit(int n) {
        int odd=0,even=0,count=0;
        while(n)
        {
            if((n&1)==1)
            {
                if(count%2==0)
                {
                    even++;
                }
                else{
                    odd++;
                }
            }
            n=n>>1;
            count++;
        }
        return {even,odd};
    }
};