class Solution {
public:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    bool isPossible(string &s1, string &s2)
    {
        if(s1.length()!=s2.length()+1)
        {
            return false;
        }
        int i=0;
        int j=0;
        while(i<s1.length())
        {
            if(s1[i]==s2[j] && j<s2.length())
            {
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s1.length() && j==s2.length())
        {
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n=words.size();
        int maxi=0;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(isPossible(words[i],words[prev]) && dp[prev]+1>dp[i])
                {
                    dp[i]=dp[prev]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};