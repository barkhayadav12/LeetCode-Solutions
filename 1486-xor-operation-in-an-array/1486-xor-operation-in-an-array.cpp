class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        int cnt=n;
        while(n!=0)
        {
            ans^=start;
            start+=2;
            n--;
        }
        return ans;
        
    }
};