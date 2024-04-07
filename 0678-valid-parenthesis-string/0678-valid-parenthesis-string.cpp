class Solution {
public:
    bool checkValidString(string s) {
        stack<int>star,op_brac;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                op_brac.push(i);
            }
            else if(s[i]=='*')
            {
                star.push(i);
            }
            else{
                if(!op_brac.empty())
                {
                    op_brac.pop(); 
                }
                else if(!star.empty())
                {
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!op_brac.empty())
        {
            if(star.empty() || op_brac.top()>star.top())
            {
                return false;
            }
            else{
                op_brac.pop();
                star.pop();
            }
        }
        return true;
    }
};