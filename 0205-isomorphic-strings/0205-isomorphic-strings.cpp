class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char s_temp[256]={0};
        char t_temp[256]={0};
        for(int i=0;i<s.length();i++)
        {
            if(s_temp[s[i]]==0 && t_temp[t[i]]==0)
            {
                s_temp[s[i]]=t[i];
                t_temp[t[i]]=s[i];
            }
            else if(s_temp[s[i]]!=t[i] && t_temp[t[i]]!=s[i])
            {
                return false;
            }
        }
        return true;
        
    }
};