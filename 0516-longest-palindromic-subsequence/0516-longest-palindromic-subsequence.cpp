class Solution {
public:
     int lcs(string &s, string &text2) {
        int n=s.length();
        int m=text2.length();
        int t[n+1][m+1];
        memset(t,-1,sizeof(t));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                {
                    t[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==text2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string text2=s;
        reverse(text2.begin(),text2.end());
        return lcs(s,text2);
    }
};