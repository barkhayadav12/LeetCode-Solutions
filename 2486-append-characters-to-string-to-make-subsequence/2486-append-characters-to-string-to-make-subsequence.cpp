class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        int n=t.length(),m=s.length();
        while(i<n && j<m)
        {
            if(t[i]==s[j])
            {
                i++;
            }
            j++;
        }
        return n-i;
    }
};