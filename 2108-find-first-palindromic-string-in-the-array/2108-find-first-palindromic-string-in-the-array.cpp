class Solution {
public:
    bool isPalindrome(string s)
    {
        string op=s;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++)
        {
            if(op[i]!=s[i])
            {
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string op="";
        for(int i=0;i<words.size();i++)
        {
            if(isPalindrome(words[i]))
            {
                op=words[i];
                break;
            }
        }
        return op;
    }
};