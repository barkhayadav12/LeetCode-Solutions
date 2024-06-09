class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int r=k/n;
        int rem=k%n;
        int ans=0;
        if(r%2==0)
        {
            ans=rem;
        }
        else{
            ans=n-rem;
        }
        return ans;
    }
};