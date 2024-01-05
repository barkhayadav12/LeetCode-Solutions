class Solution {
public:
    void solve(int openCount,int closeCount,vector<string>&v,string op)
    {
        if(openCount==0 && closeCount==0)
        {
            v.push_back(op);
            return;
        }
        if(openCount!=0)
        {
            string op1=op;
            op1.push_back('(');
            solve(openCount-1,closeCount,v,op1);
        }
        if(closeCount>openCount)
        {
            string op1=op;
            op1.push_back(')');
            solve(openCount,closeCount-1,v,op1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string op="";
        solve(n,n,v,op);
        return v;
    }
};