class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mppWin;
        map<int,int>mppLose;

        vector<vector<int>>ans;
        vector<int>win;
        vector<int>lose;

        for(int i=0;i<matches.size();i++)
        {
            mppWin[matches[i][0]]++;
            mppLose[matches[i][1]]++;
        }
        for(auto i:mppWin)
        {
            if(mppLose.find(i.first)==mppLose.end())
            {
                win.push_back(i.first);
            }
        }
        ans.push_back(win);
        for(auto i:mppLose)
        {
            int x=i.second;
            if(x==1)
            {
                lose.push_back(i.first);
            }
        }
        ans.push_back(lose);
        return ans;
    }
};