class Solution {
public:
    int passThePillow(int n, int time) {
        //n-1 mein 1 round complete kr leti hai
        int complete_rounds=time/(n-1);
        int rem_time=time%(n-1);
        if(complete_rounds%2==1)
        {
            return n-rem_time;
        }
        else{
            return rem_time+1;
        }
    }
};