class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mpp;
        for(int i=0;i<t.length();i++)
        {
            mpp[t[i]]++;
        }
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(mpp.find(s[i])!=mpp.end())
            {
                mpp[s[i]]--;
            }
        }
        for(auto i:mpp)
        {
            if(i.second>0)
            {
                cnt+=i.second;
            }
        }
        return cnt;
    }
};