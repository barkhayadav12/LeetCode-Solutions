class Solution {
public:
    string removeDigit(string number, char digit) {
       string op="";
        int cnt=0;
       for(int i=0;i<number.length();i++)
       {
           if(number[i]==digit)
           {
               cnt++;
           }
       }
       if(cnt==1)
       {
           for(int i=0;i<number.length();i++)
           {
               if(number[i]==digit)
               {
                   continue;
               }
               else{
                   op+=number[i];
               }
           }
       }
        else{
            bool flag=false;
            for(int i=0;i<number.length()-1;i++)
            {
                if(number[i]==digit && flag==false)
                {
                    int first=number[i]-'0';
                    int second=number[i+1]-'0';
                    if(first>=second)
                    {
                        op+=number[i];
                    }
                    else{
                        flag=true;
                        continue;
                    }
                }
                else{
                    op+=number[i];
                }
            }
            op+=number[number.length()-1];
            if(flag==false)
            {
                op="";
                for(int i=number.length()-1;i>=0;i--)
                {
                    if(number[i]==digit && flag==false)
                    {
                        flag=true;
                        continue;
                    }
                    else{
                        op+=number[i];
                    }
                }
                reverse(op.begin(),op.end());
            }
        }
        return op;
    }
};