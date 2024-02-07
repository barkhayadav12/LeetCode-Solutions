class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.length();i++)
        {
            mpp[s[i]]++;
        }
        int ans=-1;
        for(int i=0;i<s.length();i++)
        {
            if(mpp[s[i]]==1)
            {
                ans=i;
                break;
            }
        }
        return ans;
        
    }
};