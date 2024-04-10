class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>q;
        sort(deck.begin(),deck.end());
        for(int i=0;i<deck.size();i++)
        {
            q.push(i);
        }
        vector<int>ans(deck.size());
        int i=0;
        while(!q.empty() && i<deck.size())
        {
            ans[q.front()]=deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
            i++;
        }
        return ans;
    }
};