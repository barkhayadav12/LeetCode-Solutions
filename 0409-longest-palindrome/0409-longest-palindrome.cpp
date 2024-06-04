class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mpp;
        for(int i=0;i<s.length();i++)
        {
            mpp[s[i]]++;
        }
        int cnt=0;
        bool flag=false;
        for(auto it:mpp)
        {
            int n=it.second;
            if(n%2==0)
            {
                cnt+=n;
            }
            else{
                cnt+=(n-1);
                flag=true;
            }
        }
        if(flag==false)
        {
            return cnt;
        }
        return cnt+1;
    }
};