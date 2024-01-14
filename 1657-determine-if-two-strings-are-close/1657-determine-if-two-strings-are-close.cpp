class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>mpp1;
        map<char,int>mpp2;
        if(word1.length()!=word2.length())
        {
            return false;
        }
        for(int i=0;i<word1.length();i++)
        {
            mpp1[word1[i]]++;
        }
        for(int i=0;i<word2.length();i++)
        {
            mpp2[word2[i]]++;
        }
        for(auto i:mpp1)
        {
            if(mpp2.find(i.first)==mpp2.end())
            {
                return false;
            } 
        }
        vector<int>v1;
        vector<int>v2;
        for(auto i:mpp1)
        {
            v1.push_back(i.second);
        }
        for(auto i:mpp2)
        {
            v2.push_back(i.second);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
};