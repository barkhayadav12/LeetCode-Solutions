class Solution {
public:
    void print(vector<string>&v,string s,string op)
    {
        if(s.length()==0)
        {
            v.push_back(op);
            return;
        }
        if(isalpha(s[0]))
           {
               string op1=op;
               string op2=op;
               op1.push_back(tolower(s[0]));
               op2.push_back(toupper(s[0]));
               s.erase(s.begin()+0);
               print(v,s,op1);
               print(v,s,op2);
           }
        else{
            string op1=op;
            op1.push_back(s[0]);
            s.erase(s.begin()+0);
            print(v,s,op1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>v;
        string op="";
        print(v,s,op);
        return v;
    }
};