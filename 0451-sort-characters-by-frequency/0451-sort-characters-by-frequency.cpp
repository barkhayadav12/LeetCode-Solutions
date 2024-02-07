class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mpp;
        for(int i=0;i<s.length();i++)
        {
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>>maxHeap;
        for(auto i:mpp)
        {
            maxHeap.push({i.second,i.first});
        }
        s="";
        while(!maxHeap.empty())
        {
            s+=string(maxHeap.top().first,maxHeap.top().second);
            maxHeap.pop();
        }
        return s;
        
        
    }
};