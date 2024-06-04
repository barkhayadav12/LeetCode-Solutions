class Solution {
public:
    int secondHighest(string s) {
       vector<int>v;
        for(int i=0;i<s.length();i++)
        {
            int n=s[i]-'0';
            if(n>=0 && n<=9)
            {
                v.push_back(n);
            }
        }
            bool flag=false;
            int maxi=0;
            for(auto it:v)
            {
                maxi=max(maxi,it);
            }
            int ans=0;
            for(auto it:v)
            {
                if(it!=maxi)
                {
                    ans=max(ans,it);
                    flag=true;
                }
            }
            if(v.empty() || flag==false)
            {
                return -1;
            }
        else{
            return ans;
        }
    }
};