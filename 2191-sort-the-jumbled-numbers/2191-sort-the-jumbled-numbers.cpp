
class Solution {
public:
    static bool cmp(pair<int,pair<int,int>>a, pair<int,pair<int,int>>b) {
        if(a.second.second!=b.second.second)
        {
            return a.first<b.first;
        }
        else{
            return a.second.second<b.second.second;
        }
     }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,int>mpp;
        //mappings
        for(int i=0;i<=9;i++)
        {
            mpp[i]=mapping[i];
        }
        // converting input to string
        vector<pair<string,pair<int,int>>>s;
        for(int i=0;i<nums.size();i++)
        {
            s.push_back({to_string(nums[i]),{nums[i],i}});
        }
        // mapping to its value
        vector<pair<string,pair<int,int>>>ans;
        for(auto it:s)
        {
            string temp=it.first;
            string op="";
            for(int i=0;i<temp.length();i++)
            {
                int x=temp[i]-'0';
                int num=mpp[x];
                op+=to_string(num);
            }
            ans.push_back({op,{it.second.first,it.second.second}});
        }
        // converting back to int
        vector<pair<int,pair<int,int>>>v;
        for(auto it:ans)
        {
            int num=stoi(it.first);
            v.push_back({num,{it.second.first,it.second.second}});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>p;
        for(auto it:v)
        {
            p.push_back(nums[it.second.second]);
        }
        return p;
    }
};