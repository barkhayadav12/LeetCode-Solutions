class Solution {
public:
    string reverseParentheses(string s) {
      stack<int>stk;
        string op="";
      for(int i=0;i<s.length();i++)
      {
          if(s[i]=='(')
          {
              stk.push(op.length());
          }
          else if(s[i]==')')
          {
              int start_index=stk.top();
              stk.pop();
              reverse(op.begin()+start_index,op.end());
          }
          else{
              op+=s[i];
          }
      }
        return op;
    }
};