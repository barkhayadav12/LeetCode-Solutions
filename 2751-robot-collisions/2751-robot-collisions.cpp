class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
       //position,ind
        int n=positions.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({positions[i],i});
        }
        //sort acc to their positions
        sort(vec.begin(),vec.end());
        //positions
        stack<int>stk;
        vector<int>ans;
        for(auto it:vec)
        {
            if(directions[it.second]=='R')
            {
                stk.push(it.second);
            }
            else{
                if(stk.empty())
                {
                    ans.push_back(it.second);
                }
                else{
                    while(!stk.empty() && healths[it.second]>healths[stk.top()])
                    {
                        stk.pop();
                        healths[it.second]--;
                    }
                    if(stk.empty())
                    {
                        ans.push_back(it.second);
                    }
                    else
                    {
                        
                       if(healths[it.second]==healths[stk.top()])
                       {
                             stk.pop();
                        }
                        else{
                        healths[stk.top()]--;
                        if(healths[stk.top()]==0)
                        {
                            stk.pop();
                        }
                        }
                    }
                }
            }
        }
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        sort(ans.begin(),ans.end());
        vector<int>v;
        for(int i=0;i<ans.size();i++)
        {
            v.push_back(healths[ans[i]]);
        }
        return v;
            
    }
};