class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mpp;
        for(int i=0;i<word.length();i++)
        {
            mpp[word[i]]++;
        }
        int ans=0;
        vector<int>v;
        for(auto it:mpp)
        {
            v.push_back(it.second);
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++)
        {
            if(i<=7)
            {
                ans+=v[i];
            }
            else if(i>7 && i<=15)
            {
                ans+=2*v[i];
            }
            else if(i>15 && i<=23)
            {
                ans+=3*v[i];
            }
            else{
                ans+=4*v[i];
            }
        }
        return ans;
    }
};