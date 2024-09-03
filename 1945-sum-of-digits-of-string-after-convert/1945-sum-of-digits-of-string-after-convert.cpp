class Solution {
public:
    int getLucky(string s, int k) {
        int ans=0;
        string temp="";
        // string to num convert
        for(int i=0;i<s.length();i++)
        {
            temp+=to_string(s[i]-'a'+1);
        }
        int sum=0;
        while(k--)
        {
            sum=0;
            // add the characters
            for(int i=0;i<temp.size();i++)
            {
                sum+=(temp[i]-'0');
            }
            temp=to_string(sum);
        }
        return sum;
    }
};