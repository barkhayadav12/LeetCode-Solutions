class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        deque<int>dq;
        for(int i=1;i<skills.size();i++)
        {
            dq.push_back(i);
        }
        int win_cnt=0;
        int win_elt=0;
        while(true)
        {
            int elt=dq.front();
            dq.pop_front();
            if(skills[elt]>skills[win_elt])
            {
                win_cnt=1;
                dq.push_back(win_elt);
                win_elt=elt;
            }
            else{
                win_cnt++;
                dq.push_back(elt);
            }
            if(win_cnt==k || win_cnt>=skills.size()-1)
            {
                return win_elt;
            }
        }
        return 1;
    }
};