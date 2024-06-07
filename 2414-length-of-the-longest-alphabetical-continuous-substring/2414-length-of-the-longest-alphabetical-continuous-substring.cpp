class Solution {
public:
    int longestContinuousSubstring(string s) {
        int maxi=0;
        int num=s[0]-'a';
        int cnt=1;
        if(s.length()==1)
        {
            return 1;
        }
        for(int i=1;i<s.length();i++)
        {
            int n=s[i]-'a';
            if(n-num==1)
            {
                cnt++;
            }
            else{
                cnt=1;
            }
            num=n;
            maxi=max(cnt,maxi);
        }
        return maxi;
    }
};