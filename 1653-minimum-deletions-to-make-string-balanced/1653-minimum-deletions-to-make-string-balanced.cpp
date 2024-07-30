class Solution {
public:
    int minimumDeletions(string s) {
        stack<int>stk;
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(!stk.empty())
            {
                if(stk.top()=='b' && s[i]=='a')
                {
                    cnt++;
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
            }
            else{
                stk.push(s[i]);
            }
        }
        return cnt;
    }
};