class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26,INT_MAX);
        for(auto word:words)
        {
            vector<int>v(26,0);
            for(auto c:word)
            {
                v[c-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                minFreq[i]=min(minFreq[i],v[i]);
            }
        }
        vector<string>s;
        for(int i=0;i<26;i++)
        {
            if(minFreq[i]>0)
            {
                while(minFreq[i]>0)
                {
                    s.push_back(string(1, i + 'a'));
                    minFreq[i]--;
                }
            }
        }
        return s;
    }
};