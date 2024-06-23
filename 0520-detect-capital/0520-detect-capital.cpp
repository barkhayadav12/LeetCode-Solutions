class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        for(int i=0;i<word.length();i++)
        {
            if(isupper(word[i]))
            {
                cnt++;
            }
        }
        if(cnt==0 || cnt==word.length())
        {
            return true;
        }else if(cnt==1 && isupper(word[0]))
        {
            return true;
        }
        return false;
    }
};