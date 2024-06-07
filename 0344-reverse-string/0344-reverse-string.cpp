class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>op;
        for(int i=s.size()-1;i>=0;i--)
        {
            op.push_back(s[i]);
        }
        s=op;
    }
};