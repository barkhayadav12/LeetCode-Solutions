class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>stk;
        for(int i=0;i<num.length();i++)
        {
            while(!stk.empty() && k>0 && stk.top()>num[i])
            {
                k--;
                stk.pop();
            }
            stk.push(num[i]);
            if(stk.size()==1 && stk.top()=='0')
            {
                stk.pop();
            }
        }
        while(!stk.empty() && k>0)
        {
            k--;
            stk.pop();
        }
        string res="";
        while(!stk.empty())
        {
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        if(res=="")
        {
            return "0";
        }
        else{
            return res;
        }
    }
};