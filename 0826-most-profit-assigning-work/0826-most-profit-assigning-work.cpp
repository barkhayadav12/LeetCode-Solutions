class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>vec;
        int n=profit.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back({difficulty[i],profit[i]});
        }
        sort(vec.begin(),vec.end());
        sort(worker.begin(),worker.end());
        int pro=0;
        int j=0;
        int res=0;
        int temp=0;
        for(int i=0;i<worker.size();i++)
        {
            int num=worker[i];
            while(j<n && num>=vec[j].first)
            {
                temp=max(temp,vec[j].second);
                j++;
            }
            res+=temp;
        }
        return res;
    }
};