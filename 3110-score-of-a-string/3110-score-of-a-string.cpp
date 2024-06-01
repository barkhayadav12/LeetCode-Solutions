class Solution {
public:
    int scoreOfString(string s) {
        int cnt=0;
        for(int i=1;i<s.length();i++)
        {
            cnt+=(abs((s[i-1]-97)-(s[i]-97)));
        }
        return cnt;
    }
};