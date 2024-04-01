class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        bool flag=false;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]==' ' && flag)
            {
                break;
            }
            if(s[i]!=' ')
            {
                cnt++;
                flag=1;
            }
        }
        return cnt;
    }
};