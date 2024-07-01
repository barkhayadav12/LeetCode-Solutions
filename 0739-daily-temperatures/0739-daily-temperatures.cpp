class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //pair- number,index
        stack<pair<int,int>>stk;
        vector<int>ans;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--)
        {
            while(stk.size()>0 && stk.top().first<=temperatures[i])
            {
                stk.pop();
            }
            if(stk.size()==0)
            {
                ans.push_back(0);
            }
            else{
                ans.push_back(stk.top().second-i);
            }
            stk.push({temperatures[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};