class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int prev=-1;
        int end=-1;
        double ans=0.0;
        long long sum=0;
        for(int i=0;i<customers.size();i++)
        {
            int arrival_time=customers[i][0];
            if(arrival_time<=prev || arrival_time<=end)
            {
                arrival_time=end;
            }
            int time_taken=customers[i][1];
            int final_time=arrival_time+time_taken;
            sum+=final_time-customers[i][0];
            prev=customers[i][0];
            end=final_time;
        }
        ans=(double)sum/(double)customers.size();
        return ans;
    }
};