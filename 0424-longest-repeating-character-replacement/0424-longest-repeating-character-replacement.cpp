class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int maxf=0;
        int maxi=0;
        unordered_map<char,int>mpp;
        while(j<s.length())
        {
            mpp[s[j]]++;
            maxf=max(maxf,mpp[s[j]]);
            while((j-i+1)-maxf>k)
            {
                mpp[s[i]]--;
                if(mpp[s[i]]==0)
                {
                    mpp.erase(s[i]);
                }
                i++;
            }
            if((j-i+1)-maxf<=k)
            {
                maxi=max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};