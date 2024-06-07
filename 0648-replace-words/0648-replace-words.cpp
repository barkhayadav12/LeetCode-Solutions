class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>s(dictionary.begin(),dictionary.end());
        string ans="";
        int i=0;
        while(i<sentence.length())
        {
            string word="";
            bool flag=false;
            while(i<sentence.length() && sentence[i]!=' ')
            {
                if(flag==true)
                {
                    i++;
                    continue;
                }
                word+=sentence[i];
                i++;
                if(s.find(word)!=s.end())
                {
                    flag=true;
                }
            }
            ans+=word;
            if(i<sentence.length() && sentence[i]==' ')
            {
                ans+=" ";
            }
            i++;
        }
        return ans;
    }
};