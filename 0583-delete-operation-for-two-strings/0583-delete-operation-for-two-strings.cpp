class Solution {
public:
    int lcs(string &word1, string &word2) {
        int n=word1.size();
        int m=word2.size();
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
                if(word1[i-1]==word2[j-1])
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
    int minDistance(string word1, string word2) {
        int x=lcs(word1,word2);
        int n=word1.length();
        int m=word2.length();
        int ans=abs(x-n)+abs(x-m);
        return ans;
    }
};