class Solution {
public:
    string makeGood(string s) {
        stack<char>stk;
        for(int i=0;i<s.length();i++)
        {
            stk.push(s[i]);
            while(stk.size()>=2)
            {
                int x=stk.top();
                stk.pop();
                int y=stk.top();
                stk.pop();
                if((abs(x-y)!=32))
                {
                    stk.push(y);
                    stk.push(x); 
                    break;
                }
            }
        }
        string str="";
        while(!stk.empty())
        {
            str+=stk.top();
            stk.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};