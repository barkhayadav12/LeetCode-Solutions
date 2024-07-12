class Solution {
public:
    int points_ab(string &s,int x,stack<char>&stk)
    {
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
            }
            else{
                char ch=stk.top();
                char curr=s[i];
                if(ch=='a' && curr=='b')
                {
                    cnt+=x;
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
            }
        }
        return cnt;
    }
    int points_ba(string &s,int y,stack<char>&stk)
    {
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
            }
            else{
                char ch=stk.top();
                char curr=s[i];
                if(ch=='b' && curr=='a')
                {
                    cnt+=y;
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
            }
        }
        return cnt;
    }
    int maximumGain(string s, int x, int y) {
        if(s.length()<=1)
        {
            return 0;
        }
        stack<char>stk;
        int score=0;
        if(x>=y)
        {
            score+=points_ab(s,x,stk);
            string temp="";
            while(!stk.empty())
            {
                temp+=stk.top();
                stk.pop();
            }
            reverse(temp.begin(),temp.end());
            score+=points_ba(temp,y,stk);
        }else{
            score+=points_ba(s,y,stk);
            string temp="";
            while(!stk.empty())
            {
                temp+=stk.top();
                stk.pop();
            }
            reverse(temp.begin(),temp.end());
            score+=points_ab(temp,x,stk);
        }
        return score;
    }
};